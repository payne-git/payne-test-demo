#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
	char *i = malloc(24);

	sprintf(i, "12345");

	char *j = i;

	printf("i:%p, j:%p\n", i, j);

	free(i);

	i = NULL;

	i = j;
	
	printf("i:%p, j:%p\n", i, j);

	printf("j:%s\n", j);

	printf("i:%s\n", i);

#if 1
	printf("j + 2:%p\n", (j + 2));

	printf("j + 4:%p\n", (j + 4));
#endif

	return 0;
}
