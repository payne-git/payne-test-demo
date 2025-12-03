#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main()
{
    const char *s;
    char buf_tmp[] = "::respawn:/sbin/getty -L ttyS0 9600 linux";
    char *buf = NULL;

    buf = (char *)malloc(64);

    printf("sizeof(buf_tmp) : %d\n", sizeof(buf_tmp));

    memcpy(buf, buf_tmp, sizeof(buf_tmp));

    for (s = buf; *s != '\0';) {
        if (*s++ == '/')
            buf = s;
    }

    printf("buf : %s\n", buf);

    return 0;
}

