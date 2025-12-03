#include <stdio.h>



int *arr1[3];

int arr2[5] = {1, 2, 3, 4, 5};

int arr3[4] = {6, 7, 8, 9};

struct rp {
    int a;
    int b;
};

int main()
{
    int i, j;

    struct rp *rps[2] = {NULL};

    arr1[0] = arr2;

    arr1[2] = arr3;

    printf("sizeof(rps):%ld\n", sizeof(rps));

#if 0
    for(i = 0; i < 0; i++)
    {
        printf("i:%d\n", i);
        if(i == 0){
            for(j = 0; j < 5; j++){
                printf("arr1[%d][%d] = %d\n", i, j, arr1[i][j]);
            }
        } else if(i == 2){
            for(j = 0; j < 4; j++){
                printf("arr1[%d][%d] = %d\n", i, j, arr1[i][j]);
            }
        }else
            continue;
    }
#endif

    printf("end\n");

    return 0;
}
