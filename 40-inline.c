#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


static inline int RET(int arg)
{
    if (arg) {
        printf("arg:%d\n",arg);
        return 0;
    }
    return 0;
}


int main()
{
    int i = 0;

    printf("L:%d, i:%d\n", __LINE__, i);
    RET(i);
    printf("L:%d, i:%d\n", __LINE__, i);
    i++;
    printf("L:%d, i:%d\n", __LINE__, i);
    RET(i);
    printf("L:%d, i:%d\n", __LINE__, i);

    return 0;
}
