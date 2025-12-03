#include <stdio.h>


int main()
{
    int a = 3;

    int b = 9;

    const int *p = &a;

    int *const q = &a;

    printf("p:%p, p:%d, q:%p, q:%d\n", p, *p, q, *q);
    
    *p = 4;

    p = &b;

    *q = 5;

    q = &b;

    printf("p:%p, p:%d, q:%p, q:%d\n", p, *p, q, *q);
    
    return 0;
}
