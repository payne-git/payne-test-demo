#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{
    char *buf = " 31 ";
    //char *buf = " 931.51 ";

    int ret = 0;
    
    double buf_d = 0;
    char *ptr = NULL;

    buf_d = strtod(buf, &ptr);
    if (ptr)
        printf("buf_d : %f\n", buf_d);
    else
        printf("strtod failed\n");

    ret = (int)(buf_d * 80 / 100);
    printf("ret : %d%%\n", ret);

    return 0;
}
