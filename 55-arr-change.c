#include <stdio.h>
#include <stdlib.h>


struct rp {
    int a;
    int b;
    int c[0];
    int d;
    int e;
};

int main()
{
    int i, j;

    struct rp *rps = (struct rp*)malloc(sizeof(struct rp));

    rps->a = 0;
    rps->b = 1;
    rps->c[0] = 2;
    rps->d = 3;
    rps->e = 4;

    printf("sizeof(rps):%ld\n", sizeof(*rps));

    printf("rps->a:%d, rps->b:%d, rps->c[0]:%d, rps->d:%d, rps->e:%d\n", rps->a, rps->b, rps->c[0], rps->d, rps->e);

    printf("end\n");

    return 0;
}
