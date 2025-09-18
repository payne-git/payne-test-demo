#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define BUFLEN 1024

int main(int argc, char *argv[])
{
    int ip4_addr = 0;
    int ip_tmp = 0;
	int port_tmp = 0;
	char buf[128];
	char ip0[128];
	char port0[128];

	puts("Please input type, for example:ip, port");
	
	scanf("%s", buf);
	
	if (!strcmp(buf, "ip")) {
		puts("Please input ipaddr, for example:???");
		
		scanf("%s", ip0);
		printf("L:%d, ip0:%s\n", __LINE__, ip0);

		if (inet_aton(ip0, (struct in_addr *)&ip4_addr) == 0)
			return -1;

		ip_tmp = ntohl(ip4_addr);

		printf("L:%d, ntohl(ip):%d\n", __LINE__, ip_tmp);
	} else if (!strcmp(buf, "port")) {
		puts("Please input port, for example:61934");
		
		scanf("%s", port0);
		printf("L:%d, port0:%s, atoi(port0):%d\n", __LINE__, port0, atoi(port0));

		port_tmp = ntohl(atoi(port0));

		printf("L:%d, ntohl(port):%d, htonl(atoi(port0)):%d\n", __LINE__, port_tmp, htonl(atoi(port0)));
	}

    return 0;
}
