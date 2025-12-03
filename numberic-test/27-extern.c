#include <stdio.h>


extern int test_func(void);

int main()
{
    char tmpbuf[64] = {0};
    FILE *fp = fopen("/proc/tos/fastcpu_rate","r");

#ifdef CONFIG_TEST
    printf("test CONFIG_TEST\n");
#endif

#ifdef CONFIG_TEST_2
    printf("test CONFIG_TEST_2\n");
#endif

    if(!fp) {
        printf("fp is NULL!\n");
        return -1;
    }

    printf("start\n");

    while (fgets(tmpbuf, sizeof(tmpbuf), fp)) {
        printf("tmpbuf : %s\n", tmpbuf);
    }

    if(fp)
        fclose(fp);

    printf("end\n");

    return 0;
}
