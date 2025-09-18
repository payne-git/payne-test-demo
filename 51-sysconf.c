#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int cpu_num = 0, cpu_online = 0;

    cpu_num = (int)sysconf(_SC_NPROCESSORS_ONLN);

    cpu_online = (int)sysconf(_SC_NPROCESSORS_ONLN);

    printf("cpu_num:%d, cpu_online:%d\n", cpu_num, cpu_online);

    printf("###end###\n");

    return 0;
}
