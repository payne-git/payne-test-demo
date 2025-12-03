#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    char buf[64] = "";
    FILE *fp = NULL;
    int hash_num_int = 0;
    int hash_real_int = 0;
    unsigned int hash_num_uint = 0;
    unsigned int hash_real_uint = 0;

    fp = fopen("./hash_num.txt", "r");

    if (!fp) {
        printf("fp is NULL\n");
    }
    printf("start\n");

    while (fgets(buf, 64, fp)) {
        printf("=========================\nbuf:%s",buf);

        hash_num_int = atoi(buf);
        printf("buf:%s, atoi(buf):%d\n", buf, hash_num_int);
        hash_real_int = hash_num_int % 1048575;
        printf("hash_num_int:%d\n", hash_num_int);
        printf("hash_real_int:%d\n", hash_real_int);
        
        hash_num_uint = atoi(buf);
        hash_real_uint = hash_num_uint % 1048575;
        printf("hash_num_uint:%d\n", hash_num_uint);
        printf("hash_real_uint:%d\n", hash_real_uint);
    }
    hash_num_int = atoi("a");
    printf("buf:a, atoi(a):%d\n", hash_num_int);

    printf("end\n");

    return 0;
}

