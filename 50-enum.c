#include <stdio.h>


enum my_enum{
    a,
    b,
    c,
//#define m c
    d,
    e = 0,
    f,
    g,
    h = 100,
    i,
    j
};

int main()
{
#if 1
    printf("a:%d, b:%d, c:%d, d:%d, e:%d, f:%d, g:%d, h:%d, i:%d, j:%d.\n", a, b, c, d, e, f, g, h, i, j);
#else
    printf("a:%d, b:%d, c:%d, d:%d, e:%d, f:%d, g:%d, h:%d, i:%d, j:%d, m:%d.\n", a, b, c, d, e, f, g, h, i, j, m);
#endif
    printf("sizeof(enum my_enmu):%ld.\n", sizeof(enum my_enum));

    return 0;
}
