#include <stdio.h>



int main()
{
    int i;

    for(i = 0; i < 10; i++) {
        printf("1. i:%d\n", i);
        switch(i) {
            case 1:
                printf("%d\n", i);
                continue;
            case 3:
                printf("%d\n", i);
                continue;
        }
        printf("2. i:%d\n", i);
    }

    return 0;
}
