#include <stdio.h>
#include <unistd.h>


int main()
{
    int i;
    int j;

    for (i = 0; i < 5 && j < 3; i++)
    {
        j++;
        if (i == 2) {
            printf("L:%d, i : %d, j : %d\n", __LINE__, i, j);
        } else {
            printf("L:%d, i : %d, j : %d\n", __LINE__, i, j);
            int j;
            while (j < 5) {
                j++;
                printf("L:%d, i : %d, j : %d\n", __LINE__, i, j);
            }
        }
        printf("L:%d, i : %d, j : %d\n", __LINE__, i, j);
        sleep(3);
    }
    printf("L:%d, i : %d, j : %d\n", __LINE__, i, j);

    return 0;
}
