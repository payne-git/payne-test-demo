#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TEST0{
	short a;
	//int b;
	//char c;
}test0;

typedef struct TEST1{
	char a:1;
	char b:2;
	//int d:8;
	//char c;
}test1;

typedef struct TEST2{
	int a:1;
	char d;
	//short e;
	int b:2;
	char c;
}test2;

typedef struct TEST3{
	char a:2;
	char b:2;
    char  :0;
	char d:3;
    char  :2;
    char e:1;
}test3;


int main()
{
    test1 t1;
    test3 t3;
	printf("sizeof(test0) = %ld\n", sizeof(test0));
	printf("sizeof(test1) = %ld\n", sizeof(test1));
	//printf("test1 = %p, test1.c = %p\n", &t1, &t1.c);
	printf("sizeof(test2) = %ld\n", sizeof(test2));
	printf("sizeof(test3) = %ld\n", sizeof(test3));
	printf("test3.a:%p, test3.b:%p, test3.d:%p, test3.e:%p.\n", &t3.a, &t3.b, &t3.d, &t3.e); //位域成员不可取地

	return 0;
}
