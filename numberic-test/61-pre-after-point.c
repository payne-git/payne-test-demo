#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef short __be16;

struct arphdr {
    __be16      ar_hrd;     /* format of hardware address   */
    int      ar_pro1;     /* format of protocol address   */
    __be16      ar_pro;     /* format of protocol address   */
    unsigned char   ar_hln;     /* length of hardware address   */
    unsigned char   ar_pln;     /* length of protocol address   */
    __be16      ar_op;      /* ARP opcode (command)     */

#if 0
    /*
     *  Ethernet looks like this : This bit is variable sized however...
     */
    unsigned char       ar_sha[ETH_ALEN];   /* sender hardware address  */
    unsigned char       ar_sip[4];      /* sender IP address        */
    unsigned char       ar_tha[ETH_ALEN];   /* target hardware address  */
    unsigned char       ar_tip[4];      /* target IP address        */
#endif

};


int main()
{
    struct arphdr *arp = NULL;
    char m[] = "hello";
	int i[5] = {1,2,3,4,5};
	long long j[5] = {6,7,8,9,0};
    int flags = !arp;

    printf("L:%d, F:%s, flags:%d\n", __LINE__, __FUNCTION__, flags);

    arp = malloc(sizeof(struct arphdr));

    printf("L:%d, F:%s, flags:%d\n", __LINE__, __FUNCTION__, flags);

    printf("arp:%p, sizeof(struct arphdr):%ld\n", arp, sizeof(struct arphdr));
	printf("arp + 1:%p \n", (arp + 1));
    free(arp);
    arp = NULL;
#if 0
	printf("m:%p\n", m);
	printf("i:%p\n", i);
	printf("j:%p\n", j);

	printf("m + 2:%p, %d\n", (m + 2), *(m + 2));
	printf("m + 4:%p, %d\n", (m + 4), *(m + 4));

	printf("i + 2:%p, %d\n", (i + 2), *(i + 2));
	printf("i + 4:%p, %d\n", (i + 4), *(i + 4));

	printf("j + 2:%p, %d\n", (j + 2), *(j + 2));
	printf("j + 4:%p, %d\n", (j + 4), *(j + 4));
#endif

	return 0;
}
