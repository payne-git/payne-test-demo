#include <stdio.h>
#include <unistd.h>


int main()
{
    int i, j = 0;
    int k = 1, n = 0;

    for (i = 0; i <= 0; i++)
    {
        printf("L:%d, hello i:%d\n", __LINE__, i);
    }
    printf("L:%d, i:%d\n", __LINE__, i);
    for (i = 0; i < 0; i++)
    {
        printf("L:%d, hello i:%d\n", __LINE__, i);
    }
    printf("L:%d, i:%d\n", __LINE__, i);

    for (i = 0; i < -1; i++)
    {
        printf("L:%d, hello i:%d\n", __LINE__, i);
    }
    printf("L:%d, i:%d\n", __LINE__, i);

    for (i = 0; i < 3; i++) {
        printf("L:%d, i:%d, j:%d, n:%d\n", __LINE__, i, j, n);
#if 1
        if (j == 7 || !k) {
            printf("L:%d, i:%d\n", __LINE__, i);
            k = 0;
            break;
        }
#endif
        n++;
        j++;
        if (n >= 3) {
            i = 0;
            n = 1;
            printf("L:%d, i:%d, j:%d\n", __LINE__, i, j);
            sleep(2);
            continue;
        }
    }
    printf("L:%d, i:%d\n", __LINE__, i);

    return 0;
}
