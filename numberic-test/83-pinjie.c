#include <stdio.h>


#define MAX_NUM 4

#define name1  "name_1"
#define name2  "name_2"
#define name3  "name_3"
#define name4  "name_4"


//#define TEST_DEF(x, name)    name##x

#define CONCAT_WITH_SPACE(x, y) x ## y

#if 0
void func1(int i)
{
   printf("i:%d, name:%s\n", i, TEST_DEF(i, "xu")); 
}
#endif

int main()
{
    int i = 0;

    for (i = 0; i < MAX_NUM; i++) {
        //func1(i);
    }
    char result_with_space[] = CONCAT_WITH_SPACE("hello", "world");

    printf("result_with_space:%s\n", result_with_space);

    return 0;
}
