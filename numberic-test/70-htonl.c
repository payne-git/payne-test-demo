#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main ()
{
    int a = 0xFFFFFF00;
    int b = htonl(a);

	printf("a = 0x%08x, b = 0x%08x\n", a, b);

    int c = 0xF0000000;
    int d = htonl(c);

	printf("c = 0x%08x, d = 0x%08x\n", c, d);

    int e = 0x10023004;
    int f = htonl(e);

	printf("e = 0x%08x, f = 0x%08x\n", e, f);

    return 0;
}
