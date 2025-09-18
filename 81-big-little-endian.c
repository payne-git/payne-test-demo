#include <stdio.h>

typedef union TEST{
	int a;
	char b[4];
}test;


int main()
{
    union TEST t1;
    test t2;
	t1.a = 0x11223344;
	printf("t1.a:%02x\n", t1.a);
	printf("b[0]:%02x, b[1]:%02x, b[2]:%02x, b[3]:%02x\n", t1.b[0], t1.b[1], t1.b[2], t1.b[3]);
	printf("&b[0]:%p, &b[1]:%p, &b[2]:%p, &b[3]:%p\n", &t1.b[0], &t1.b[1], &t1.b[2], &t1.b[3]);
	
	if (t1.b[0] == 0x44) {
		printf("This device is little endian\n");
	} else if (t1.b[0] == 0x11) {
		printf("This device is big endian\n");
	} else {
		printf("This device is unkown endian\n");
	}

	return 0;
}
