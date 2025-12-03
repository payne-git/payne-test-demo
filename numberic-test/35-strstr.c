#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main()
{
    char *ptr1 = "";
    char *ptr2 = "";

    ptr1 = strstr("a./sdsdfasf", "./");
    ptr2 = strstr("qweeerererre", "../");

    if( ptr1 || ptr2 )
    {
        printf("1: ptr1:%s, ptr2:%s\n", ptr1, ptr2);
    }
    printf("2: ptr1:%s, ptr2:%s\n", ptr1, ptr2);

    if (1 > 0)
        if( ptr1 || ptr2 ) {
            printf("1: ptr1:%s, ptr2:%s\n", ptr1, ptr2);
        }

    printf("end\n");
    
    return 0;
}

