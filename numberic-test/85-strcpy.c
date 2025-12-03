#include <stdio.h>
#include <string.h>



int main ()
{
    char buf[32];

    char tmp[32];

    memset(buf, 0, sizeof(buf));
    memset(tmp, 0, sizeof(tmp));
    
    strcpy(tmp, buf);

    printf("tmp:%s, buf:%s.\n", tmp, buf);

    return 0;
}

