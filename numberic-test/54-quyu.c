#include <stdio.h>


int main()
{
    int m = -32759;
    int n = 0x1234;

    printf("start\n");

    if (m % 500 == 0)
        printf("m:%d\n", m);

    printf("m \% 500:%d\n", m%500);
    printf("m \% 2:%d\n", m%2);

    printf("n : #%20x\n", n);
    printf("n : 0%#x\n", n);

    printf("end\n");

    return 0;
}
