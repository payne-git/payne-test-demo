#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void fun1(char * buf)
{
    sprintf(buf, "this is one layer point");
}

void fun2(char * buf)
{
    sprintf(buf, "this is two layer point");
}


int main()
{
    char buf[64] = {0};

    fun1(buf);

    puts(buf);

    fun2(&buf);

    puts(buf);

    return 0;
}
