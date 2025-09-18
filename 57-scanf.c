#include <stdio.h>

int main()
{
    int a;

    char b;

    char c[32];

    int ret = 0;

    ret = scanf("%d, %c, %s", &a, &b, &c);

    printf("ret:%d\n", ret);

    printf("a:%d, b:%c, c:%s\n", a, b, c);

    return 0;
}
