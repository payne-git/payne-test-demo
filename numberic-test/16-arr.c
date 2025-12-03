#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


struct name_index{
    const char name[64]; 
    int index;
};


#define FUN(_name, _index) { \
    .name = _name,  \
    .index = _index,    \
}


static const struct name_index pac_count[] = {
    FUN("1", 5),
    FUN("2", 6),
    FUN("3", 7),
    FUN("4", 8),
    FUN("5", 9),
    FUN(NULL, 0)
};





int main()
{
    int i;

    for(i = 0; i < 9; i++)
        printf("pac_count, name:%s, index:%d\n", pac_count[i].name, pac_count[i].index);

    return 0;
}
