#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main()
{
    char *buf;

    buf = (char *)malloc(10240 * 1024);

    memset(buf, 0x0, (10240 * 1024));

    sprintf(buf, "hello world");

    printf("buf:%s, buf_size:%d\n", buf, sizeof(buf));

    free(buf);

    buf = NULL;

    return 0;
}
