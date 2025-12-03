#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main (int argc, char *argv[])
{
	short a = 1;
	short n_arg = 0;
	short arg = 0;
	short num = 0;

	if (argc != 2 ) {
		puts("Please input argument, for example: ./a.out 44");
		return -1;
	}
	
	arg = atoi(argv[1]);
	
	printf("argv[1] : %d\n", arg);

	n_arg = htons(arg);

	printf("n_arg : %d\n", n_arg);

	printf("htons(ntohs(n_arg) + 1) : %d\n", htons(ntohs(n_arg) + 1));

	printf("htons(n_arg + 1) : %d\n", htons(n_arg + 1));

	printf("(n_arg + htons(1)) : %d\n", (n_arg + htons(1)));
	
	return 0;
}
