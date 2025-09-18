#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define max 5

static const char *pac_count[max] = {
    "xxxxxxxxxxxxxx",
    "dddddddddddddd",
    "rrrrrrrrrrrrrr",
    "tttttttttttttt",
    "wwwwwwwwwwwwww"
};



int main()
{
    int i;

    printf("1111\n");
    const char **buf = pac_count;
    printf("2222\n");

    //memcpy(buf, pac_count, max);

    //printf("pac_count, name:%s, index:%d\n", pac_count[0], i);
    //printf("pac_count, name:%s, index:%d\n", *buf[0], i);
    
    //for(i = 0; i < max; i++)
    for(i = 0; i < 0; i++)
        printf("pac_count, name:%s, index:%d\n", buf[i], i);
        //printf("pac_count, name:%s, index:%d\n", pac_count[i], i);
        //printf("pac_count, name:%s, index:%d\n", pac_count[i].name, pac_count[i].index);

    return 0;
}
