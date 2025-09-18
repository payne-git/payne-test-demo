#include <stdio.h>
#include <string.h>



int main ()
{
    char buf[] = "1234567890123456789012345678901234567890";

    char *m = NULL;

    char tmp[32] = "";
    
    char tmp1[] = "";
    
    printf("tmp:%s, tmp1:%s.\n", tmp, tmp1);

    strncpy(tmp, buf, 32);

    printf("tmp:%s, tmp1:%s.\n", tmp, tmp1);

    return 0;
}

