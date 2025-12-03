#include <stdio.h>

#define BITS_PER_LONG 64

unsigned long __fls(unsigned long word)
{
	int num = BITS_PER_LONG - 1;

	if (!(word & (~0ul << 32))) {
		num -= 32;
		word <<= 32;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-16)))) {
		num -= 16;
		word <<= 16;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-8)))) {
		num -= 8;
		word <<= 8;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-4)))) {
		num -= 4;
		word <<= 4;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-2)))) {
		num -= 2;
		word <<= 2;
	}
	if (!(word & (~0ul << (BITS_PER_LONG-1))))
		num -= 1;
	return num;
}


int main()
{
	unsigned long xb = 0x3000000000000000;
	unsigned long ret = 0;
	
	ret = __fls(xb);
	
	printf("ret : %lu\n", ret);
	
	return 0;
}
