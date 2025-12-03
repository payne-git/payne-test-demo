#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __u64	long long
#define __u32	int
#define __u16	short
#define __u8	char

struct	half_session {
	__u32	seq_diff ;
	__u32	slowpath;
    __u32	fastpath;
	__u32	path;
};

static char g_sys_oob_dev[16] = "eth0";

int main ()
{
    struct half_session *hs;
	printf("sizeof(struct half_session) = %ld\n", sizeof(struct half_session));
	printf("sizeof(*hs) = %ld\n", sizeof(*hs));
	printf("sizeof(hs) = %ld\n", sizeof(hs));

    printf("sizeof(g_sys_oob_dev) : %ld\n", sizeof(g_sys_oob_dev));
    printf("strlen(g_sys_oob_dev) : %ld\n", strlen(g_sys_oob_dev));

    return 0;
}
