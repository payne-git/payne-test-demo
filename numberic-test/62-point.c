#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
	char *i = malloc(24);

    char *j = i;

    long long str = (long long)i;

	sprintf(i, "12345");

    printf("i is %s in %p; j is %p; str is %x\n", i, i, j, str);

    printf("(int *)&str is %d, (int *)j is %d, (int *)&str - (int *)j is %d\n", (int *)&str, (int *)j, (int *)&str - (int *)j);

	free(i);

	i = NULL;

	printf("i is %p; j is %p; str is %x\n", i, j, str);

    //This is not true!!!
    printf("j is %s in %p\n", j, j);

    printf("end\n");

	return 0;
}
