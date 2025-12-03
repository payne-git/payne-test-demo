#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TEST{
	char a;
	double b;
	char c;
}test;


int main()
{
	printf("sizeof(double) = %d\n", sizeof(double));

	printf("sizeof(test) = %d\n", sizeof(test));

	return 0;
}
