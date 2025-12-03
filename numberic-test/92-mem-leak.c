#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
    int num = 1;
	char *i = malloc(24);

	sprintf(i, "12345");

    while(num--)
        sleep(5);

#if 0
    free(i);
#endif

	return 0;
}
