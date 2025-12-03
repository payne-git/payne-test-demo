#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rp {
    int a;
    int b;
};

int main()
{
    struct rp *rps[2] = {NULL};

#if 0
    struct rp rp_1 = {
        .a = 1,
        .b = 1,
    };

    struct rp rp_2 = {
        .a = 2,
        .b = 2,
    };

    rps[0] = &rp_1;
    rps[1] = &rp_2;
#endif

    struct rp *rp_1 = NULL;
    struct rp *rp_2 = NULL;

    rp_1 = (struct rp *)malloc(sizeof(struct rp));
    rp_2 = (struct rp *)malloc(sizeof(struct rp));

    rp_1->a = 1;
    rp_1->b = 1;

    rp_2->a = 2;
    rp_2->b = 2;

    rps[0] = rp_1;
    rps[1] = rp_2;

    printf("sizeof(rps):%ld\n", sizeof(rps));

    printf("rps[0]->a:%d, rps[0]->b:%d\n", rps[0]->a, rps[0]->b);
    printf("rps[1]->a:%d, rps[1]->b:%d\n", rps[1]->a, rps[1]->b);

    memset(rps, 0, sizeof(rps));

    printf("rp_1->a:%d, rp_1->b:%d\n", rp_1->a, rp_1->b);
    printf("rp_2->a:%d, rp_2->b:%d\n", rp_2->a, rp_2->b);

    printf("rps[0]->a:%d, rps[0]->b:%d\n", rps[0]->a, rps[0]->b);
    printf("rps[1]->a:%d, rps[1]->b:%d\n", rps[1]->a, rps[1]->b);

    printf("end\n");

    return 0;
}
