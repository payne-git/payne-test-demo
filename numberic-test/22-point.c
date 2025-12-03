#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void fun1(char *i)
{
	i = malloc(10);

	sprintf(i, "1111");

	printf("fun1: i:%p, i:%s\n", i, i);

	return;
}


int main()
{
	char *i = malloc(24);

	sprintf(i, "0000");

	printf("i:%p, i:%s\n", i, i);

	fun1(i);

	printf("i:%p, i:%s\n", i, i);

	free(i);

	i = NULL;

	return 0;
}
