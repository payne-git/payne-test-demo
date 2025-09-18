#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <execinfo.h>

#define BACKTRACE_SIZE 100

void print_backtrace()
{
    void *buffer[BACKTRACE_SIZE] = {0};
    int pointer_num = backtrace(buffer, BACKTRACE_SIZE);
    char ** string_buffer = backtrace_symbols(buffer, pointer_num);
    if (string_buffer == NULL) {
        puts("backtrace_symbols error");
        exit(-1);
    }
    printf("#################print backtrace begin#################\n");
    for(int i = 0; i < pointer_num; i++){
        printf("%d : %s\n", i, string_buffer[i]);
    }
    printf("#################print backtrace end#################\n");
    free(string_buffer);
    return;
}

int fun3()
{
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    char *buf = NULL;

    print_backtrace();

    memcpy(buf, "hello world", 10);
    printf("buf:%s\n", buf);
    printf("F:%s, L:%d, end\n", __FUNCTION__, __LINE__);
    return 0;
}

int fun2()
{
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    fun3();
    printf("F:%s, L:%d, end\n", __FUNCTION__, __LINE__);
    return 0;
}

int fun1()
{
    printf("F:%s, L:%d, start\n", __FUNCTION__, __LINE__);
    fun2();
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

