#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __u64	long long
#define __u32	int
#define __u16	short
#define __u8	char

struct in6_addr {
    //char *point;
	//char addr[40];
	int addr[40];
};

struct in_addr {
    char addr[32];
};

struct	half_session1 {
    int aa;
    struct in6_addr ipv6_saddr;
    char bb;
    struct in6_addr ipv6_daddr;
    struct in_addr ipaddr;
} ;

int main ()
{
    struct half_session1 *hs = malloc(sizeof(struct half_session1));
    if (!hs)
        return -1;
	printf("sizeof(struct half_session1) = %ld\n", sizeof(struct half_session1));
	printf("&hs->aa = %p\n", &hs->aa);
	printf("&hs->ipv6_saddr = %p\n", &hs->ipv6_saddr);
	printf("&hs->bb = %p\n", &hs->bb);
	printf("&hs->ipv6_daddr = %p\n", &hs->ipv6_daddr);
	printf("&hs->ipaddr = %p\n", &hs->ipaddr);
    free(hs);
    hs = NULL;
    return 0;
}
