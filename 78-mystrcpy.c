#include <stdio.h>
#include <string.h>


char *my_strcpy(char *dest, const char *src)
{
    char *tmp_str = dest;

    if (!dest || !src)
        return NULL;
    
    while ((*dest++ = *src++) != '\0');

    return tmp_str;
}


int main ()
{
    char buf[] = "hello world";

    char tmp[32] = "12345678901234567890";

    char *str = NULL;
    
    printf("%s\n", tmp);

    str = my_strcpy(tmp, buf);

    printf("str:%s, tmp:%s, strlen(tmp):%lu\n", str, tmp, strlen(tmp));

    return 0;
}

