#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int func(char *msg)
{
    char buf[5120] = "123456";

    printf("buf : %s\n", buf);

    sprintf(buf, "%s", msg);

    printf("buf : %s\n", buf);

    return 0;
}


int autherror[2560] = {0};
int main ()
{

    sprintf(autherror, "[ssh-correct_password]rpy_code is NULL-error");

    func(autherror);

    memset(autherror, 0, 256);

    return 0;
}

