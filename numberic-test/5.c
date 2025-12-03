#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{
    char *buf = "192.168.106.171";

    int ret = -1;

    ret = strcmp("192.168.106.171", buf);

    printf("ret : %d\n", ret);

    ret = strncmp("192.168.106.172", buf, 15);

    printf("ret : %d\n", ret);

    return 0;
}
