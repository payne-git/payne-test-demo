#include <stdio.h>



int main ()
{
    char buf[] = "hello world";

    char tmp[32] = "1234567890123456789012";
    
    printf("%s\n", tmp);

    sprintf(tmp, "%s", buf);

    printf("tmp:%s, strlen(tmp):%u\n", tmp, strlen(tmp));
    printf("%s\n", tmp);

    return 0;
}

