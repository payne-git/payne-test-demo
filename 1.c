#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if 0
int j = 0;
//const int k = 0;
//volatile const int l = 0;
#else
int j = 10;
//const int k = 20;
//volatile const int l = 30;
#endif

int main()
{
#if 0
	static int i = 0;
	static int m = 0;
	static int n = 0;
#else
	static int i = 10;
	static int m = 20;
	static int n = 30;
#endif
    char a = 200;
	printf("a : %d\n", a);
	while(1)
	{
		sleep(1);
		printf("i : %d\n", i++);
		printf("j : %d\n", j++);
		//printf("i : %d\n", \
			i++);
	}

	return 0;
}
