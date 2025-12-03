#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void func(char **buf, int num)
{
	buf[num] = NULL;
}


int main()
{
	char *buf[32] = {"aabbccdd", "123456", "qwreasdf", "vvvvvvvv"};
	
	printf("buf:%p, buf+2:%p.\n", buf, buf+2);

	printf("buf[2]:%s.\n", buf[2]);

	printf("buf+2:%s.\n", buf+2);
	
	func(buf, 2);
	
	printf("buf:%p, buf+2:%p.\n", buf, buf+2);

	printf("buf[2]:%s.\n", buf[2]);

	printf("buf+2:%s.\n", buf+2);
	

	return 0;
}
