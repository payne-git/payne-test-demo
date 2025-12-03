#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    char buf[] = "veth0.01";
    char *buf_2 = NULL;

    int ret = 0;
    
    ret = strcmp(buf, "eth");

    printf("L:%d, ret : %d\n", __LINE__, ret);

    ret = strcmp(buf_2, "enable");

    printf("L:%d, ret : %d\n", __LINE__, ret);

    return 0;
}
