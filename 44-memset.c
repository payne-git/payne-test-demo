#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char * buf = NULL;

    buf = malloc(128);
    if(!buf)
    {
        return -1;
    }

    printf("sizeof(buf) : %ld\n", sizeof(buf));

    memset(buf, 0, sizeof(buf));

    sprintf(buf, "hello world");

    printf("buf:%s\n", buf);

    printf("sizeof(buf) : %ld\n", sizeof(buf));

    free(buf);
    
    buf = NULL;

    return 0;
}
