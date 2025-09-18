#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
    unsigned char a = 255;
    unsigned int b = 5 - 10;
    int c = 5 - 10;

    printf("unsigned char a = %d\n", a);
    a++;
    printf("unsigned char a = %d\n", a++);
    printf("unsigned char a = %d\n", a);
    printf("unsigned int b = %d\n", b);
    printf("unsigned int b = %x\n", b);
    printf("int c = %d\n", c);
    printf("int c = %x\n", c);

    if((char)a < 0)
        printf("(char)a < 0\n");
    else
        printf("(char)a > 0\n");

    if((int)b < 0)
        printf("(int)b < 0\n");
    else
        printf("(int)b > 0\n");

    if(b < 0)
        printf("b < 0\n");
    else
        printf("b > 0\n");

    if((int)c < 0)
        printf("(int)c < 0\n");
    else
        printf("(int)c > 0\n");

    if(a > b)
        printf("a > b\n");
    else
        printf("a < b\n");

    if(a > c)
        printf("a > c\n");
    else
        printf("a < c\n");

    return 0;
}
