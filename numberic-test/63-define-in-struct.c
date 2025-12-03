#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct test{
    int *tt;
    int a;
    //char b;
    //short c;
};

struct test1{
    int *tt;
    int a;
    //char b;
#define m 1
#define n 2
    //short c;
};


int main()
{
    struct test t1;
    struct test1 t2;

    printf("sizeof(t1):%ld\n", sizeof(t1));
    printf("sizeof(t2):%ld\n", sizeof(t2));

    return 0;
}
