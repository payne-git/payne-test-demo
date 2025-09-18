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

};

int func(void *void_arp, char *char_arp, struct arphdr *struct_arp)
{
    void_arp++;
    printf("void_arp++:%p, sizeof(void_arp):%lu, sizeof(void):%lu\n", void_arp, sizeof(void_arp), sizeof(void));
    char_arp++;
    printf("char_arp++:%p, sizeof(char_arp):%lu, sizeof(char):%lu\n", char_arp, sizeof(char_arp), sizeof(char));
    struct_arp++;
	printf("struct_arp++:%p, sizeof(struct_arp):%lu, sizeof(struct arphdr):%lu\n", struct_arp, sizeof(struct_arp), sizeof(struct arphdr));
    return 0;
}

int main()
{
    struct arphdr *arp = NULL;
    char m[] = "world";
	int i[5] = {1,2,3,4,5};
	long long j[5] = {6,7,8,9,0};
    arp = malloc(sizeof(struct arphdr) * 3);
    printf("arp:%p, sizeof(struct arphdr):%ld\n", arp, sizeof(struct arphdr));
	printf("arp + 1:%p \n", (arp + 1));
    func(arp, (char *)arp, arp);
    free(arp);
    arp = NULL;
	printf("m:%p, m + 2:%p, *(m + 2):%c, *m + 2:%c\n", m, (m + 2), *(m + 2), *m + 2);
	printf("i:%p, i + 2:%p, *(i + 2):%d, *i + 2:%d\n", i, (i + 2), *(i + 2), *i + 2);
	printf("j:%p, j + 2:%p, *(j + 2):%lld, *j + 2:%lld\n", j, (j + 2), *(j + 2), *j + 2);
	return 0;
}
