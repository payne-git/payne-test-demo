#include <stdio.h>
#include <stdlib.h>



int main()
{
    char buf[64];

    sprintf(buf, "./8.sh");

    system(buf);

    while(1);

    return 0;
}

