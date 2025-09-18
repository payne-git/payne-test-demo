#include <stdio.h>


int main()
{
	unsigned long i = ~0;
	unsigned long j = ~0UL;

	printf("i:%lx, i:%lu\n", i, i);
	printf("j:%lx, j:%lu\n", j, j);

	return 0;
}
