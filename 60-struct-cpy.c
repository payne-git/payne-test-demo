#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TEST{
	char a;
	int b;
	char c;
}test;


int main()
{
    int ret = 0;
    test *t1 = NULL;
    test *t2 = NULL;
    test t0 = {
        .a = 'H',
        .b = 32,
        .c = 'B',
    };

    t1 = (test *)malloc(sizeof(test));
    if (!t1) {
        ret = -1;
        goto out1;
    }
    t2 = (test *)malloc(sizeof(test));
    if (!t2) {
        ret = -2;
        goto out2;
    }

    //t1 = &t0;
    *t1 = t0;
    *t2 = *t1;

	printf("t0.a:%c, t0.b:%d, t0.c:%c\n", t0.a, t0.b, t0.c);
	printf("t1->a:%c, t1->b:%d, t1->c:%c\n", t1->a, t1->b, t1->c);
	printf("t2->a:%c, t2->b:%d, t2->c:%c\n", t2->a, t2->b, t2->c);

out2:
    free(t2);
out1:
    free(t1);

	return 0;
}
