#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#pragma pack(1)
struct demo1 {
    short int a;
	char addr[3];
};

#pragma pack(push)
#pragma pack(8)
struct demo2 {
    int a;
	char addr[3];
};

int main ()
{
    printf("sizeof(struct demo1):%ld\n", sizeof(struct demo1));
    printf("sizeof(struct demo2):%ld\n", sizeof(struct demo2));
    return 0;
}
