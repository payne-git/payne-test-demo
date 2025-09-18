#include <stdio.h>


int function2(int c, int d)
{
	int ret = c + d;
	return ret;
}


int function1(int a, int b)
{
	int ret = a - b;
	ret = function2(a, ret);
	return ret;
}

int main()
{
	int i = 3, j = 1;
	int ret = function1(i, j);	
	return 0;
}
