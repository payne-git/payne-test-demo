#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




struct test{
    //struct test *tt;
    int *tt;
    int a;
    char b;
    short c;
};


int main()
{
    struct test *t1, *t2;

    t1 = (struct test*)malloc(sizeof(struct test*));

    //t2 = (struct test*)malloc(sizeof(struct test*));

    //t1->tt = t2;

    printf("t1:%p, t1->tt:%p\n", t1, &t1->tt);
    printf("t1 + 1:%p, t1->c:%p\n", t1 + 1, &t1->c);

    //free(t2);

    free(t1);

    t1 = t2 = NULL;

    return 0;
}
