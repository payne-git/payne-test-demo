#include <stdio.h>

int main()
{
    int a = -64;
    int b = 64;
    char *c = "world";
    float d = 3.1415926;
    int *e = &a;
    int f = 0x1234;

    printf(" a:%d ,\n a:%x ,\n a:%o ,\n a:%u ,\n a:%c ,\n\n b:%04d ,\n b:%x ,\n b:%o ,\n b:%u ,\n b:%c ,\n c:%s ,\n d:%f ,\n e:%p ,\n d:%e ,\n\n", a, a, a, a, a, b, b, b, b, b, c, d, e, d);

    printf(" f:%#x ,\n f:%#o ,\n a:%+d ,\n\n", f, f, a);

    printf(" a:%16x ,\n a:%#16x ,\n a:%-#16x ,\n a:%0#16x ,\n a:%016x ,\n a:%06x ,\n a:%-0#16x ,\n\n ", a, a, a, a, a, a);

    return 0;
}
