#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


static char dev_name[16] = "eth0";


char * get_dev_name()
{
    return dev_name;
}


int main(int argc, char *argv[])
{
    char * buf = argv[1];

    if (!argv[1]) {
        puts("please input argv[1] for devname");
        return -1;
    }

    printf("buf:%s\n", buf);

    if (!memcmp(buf, get_dev_name(), 16)) {
        printf("L:%d, buf:%s == dev_name:%s\n", __LINE__, buf, get_dev_name());
    }

    if (!strncmp(buf, get_dev_name(), sizeof(dev_name))) {
        printf("L:%d, buf:%s == dev_name:%s\n", __LINE__, buf, get_dev_name());
    }

    if (!strncmp(buf, get_dev_name(), 4)) {
        printf("L:%d, buf:%s == dev_name:%s\n", __LINE__, buf, get_dev_name());
    }

    printf("dev_name:%s\n", get_dev_name());

    return 0;
}
