#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct test{
    int *tt;
    int a;
    //char b;
    short c;
};

enum m {
    x = 0,
    y,
    z,
    w,
    s
};
struct test1{
    int *tt;
    int a;
    //char b;
    enum m M;
    short c;
};


int main()
{
    struct test t1;
    struct test1 t2;

    printf("sizeof(t1):%ld\n", sizeof(t1));
    printf("sizeof(t2):%ld\n", sizeof(t2));

    printf("t1:%p\n", &t1);
    printf("t2:%p\n", &t2);

    printf("t1.c:%p\n", &t1.c);
    printf("t2.c:%p\n", &t2.c);

    return 0;
}
