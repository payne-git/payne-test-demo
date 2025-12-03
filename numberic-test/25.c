#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
	void * addr = main;
	
	void * p = (void *)__FUNCTION__;

	printf("addr:%p, p:%p\n", addr, p);

	printf("addr:%s, p:%s\n", addr, p);

	return 0;
}
