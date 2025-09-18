#define _ATFILE_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/inotify.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>
#define __USE_GNU
#include <sched.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <linux/limits.h>
#include <linux/net_namespace.h>



#if 0
#include "utils.h"
#include "list.h"
#include "ip_common.h"
#include "namespace.h"
#endif



#define NETNS_RUN_DIR "/var/run/netns"

#ifndef CLONE_NEWNET
#define CLONE_NEWNET 0x40000000	/* New network namespace (lo, device, names sockets, etc) */
#endif


static int on_netns_del(char *nsname, void *arg)
{
	char netns_path[PATH_MAX];

	snprintf(netns_path, sizeof(netns_path), "%s/%s", NETNS_RUN_DIR, nsname);
	umount2(netns_path, MNT_DETACH);
	if (unlink(netns_path) < 0) {
		fprintf(stderr, "Cannot remove namespace file \"%s\": %s\n",
			netns_path, strerror(errno));
		return -1;
	}
	return 0;
}

int netns_foreach(int (*func)(char *nsname, void *arg), void *arg)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(NETNS_RUN_DIR);
	if (!dir)
		return -1;

	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0)
			continue;
		if (strcmp(entry->d_name, "..") == 0)
			continue;
		if (func(entry->d_name, arg))
			break;
	}

	closedir(dir);
	return 0;
}


static int netns_delete(int argc, char **argv)
{
	if (argc < 1) {
		fprintf(stderr, "No netns name specified\n");
		return -1;
	}

	return on_netns_del(argv[0], NULL);
}


static int create_netns_dir(void)
{
	/* Create the base netns directory if it doesn't exist */
	if (mkdir(NETNS_RUN_DIR, S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)) {
		if (errno != EEXIST) {
			fprintf(stderr, "mkdir %s failed: %s\n",
				NETNS_RUN_DIR, strerror(errno));
			return -1;
		}
	}

	return 0;
}

int netns_add(int argc, char **argv)
{
	/* This function creates a new network namespace and
	 * a new mount namespace and bind them into a well known
	 * location in the filesystem based on the name provided.
	 *
	 * The mount namespace is created so that any necessary
	 * userspace tweaks like remounting /sys, or bind mounting
	 * a new /etc/resolv.conf can be shared between uers.
	 */
	char netns_path[32];
	const char *name;
	int fd;
	int made_netns_run_dir_mount = 0;

	if (argc < 1) {
		fprintf(stderr, "No netns name specified\n");
		return -1;
	}
	name = argv[0];

	snprintf(netns_path, sizeof(netns_path), "%s/%s", NETNS_RUN_DIR, name);

	if (create_netns_dir())
		return -1;

	/* Make it possible for network namespace mounts to propagate between
	 * mount namespaces.  This makes it likely that a unmounting a network
	 * namespace file in one namespace will unmount the network namespace
	 * file in all namespaces allowing the network namespace to be freed
	 * sooner.
	 */
	while (mount("", NETNS_RUN_DIR, "none", MS_SHARED | MS_REC, NULL)) {
		/* Fail unless we need to make the mount point */
		if (errno != EINVAL || made_netns_run_dir_mount) {
			fprintf(stderr, "mount --make-shared %s failed: %s\n",
				NETNS_RUN_DIR, strerror(errno));
			return -1;
		}

		/* Upgrade NETNS_RUN_DIR to a mount point */
		if (mount(NETNS_RUN_DIR, NETNS_RUN_DIR, "none", MS_BIND, NULL)) {
			fprintf(stderr, "mount --bind %s %s failed: %s\n",
				NETNS_RUN_DIR, NETNS_RUN_DIR, strerror(errno));
			return -1;
		}
		made_netns_run_dir_mount = 1;
	}

	/* Create the filesystem state */
	fd = open(netns_path, O_RDONLY|O_CREAT|O_EXCL, 0);
	if (fd < 0) {
		fprintf(stderr, "Cannot create namespace file \"%s\": %s\n",
			netns_path, strerror(errno));
		return -1;
	}
	close(fd);
	if (unshare(CLONE_NEWNET) < 0) {
		fprintf(stderr, "Failed to create a new network namespace \"%s\": %s\n",
			name, strerror(errno));
		goto out_delete;
	}

	/* Bind the netns last so I can watch for it */
	if (mount("/proc/self/ns/net", netns_path, "none", MS_BIND, NULL) < 0) {
		fprintf(stderr, "Bind /proc/self/ns/net -> %s failed: %s\n",
			netns_path, strerror(errno));
		goto out_delete;
	}
	return 0;
out_delete:
	netns_delete(argc, argv);
	return -1;
}



int main(int argc, char *argv[])
{
	netns_add(argc-1, argv+1);

	return 0;
}