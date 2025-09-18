#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void bprint(int p){
	int i = 0;
	int bit1 = 1;
	for (i = sizeof(p) * 8 - 1; i >= 0; i--) {
		unsigned int x = (((bit1 << i) & p) != 0);
		printf("%d", x);
	}
	printf("\n");
}


int main()
{
	int num = 14;

	int tmp = ~(1 << 4);

	//printf("tmp : %04x\n", tmp);
	bprint(tmp & num);

	if (num & 1) {
		printf("FATAL\n");
	}
	if (num & 1 << 1) {
		printf("ABNORMAL\n");
	}
	if (num & 1 << 2) {
		printf("ROUTINE\n");
	}
	if (num & 1 << 3) {
		printf("DETAIL\n");
	}

	return 0;
}
