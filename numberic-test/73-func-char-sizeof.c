#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKTRACE_SIZE 100

int fun2(char *buf)
{
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    printf("buf:%s\n", buf);
    printf("sizeof(buf):%lu\n", sizeof(buf));
    printf("F:%s, L:%d, end\n", __FUNCTION__, __LINE__);
    return 0;
}

int fun1()
{
    char buf[BACKTRACE_SIZE];
    sprintf(buf, "hello, this is func1, the buf size is %d, sizeof(buf) is %lu", BACKTRACE_SIZE, sizeof(buf));
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    fun2(buf);
    printf("F:%s, L:%d, end\n", __FUNCTION__, __LINE__);
    return 0;
}

int main()
{
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    fun1();
    printf("F:%s, L:%d, end\n", __FUNCTION__, __LINE__);
    return 0;
}

