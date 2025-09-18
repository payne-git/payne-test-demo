#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
    int offset = 0;

    int fd = open("/proc/tos_debug_statistics_module", O_RDONLY);

    if (fd < 0) {
        printf("fail to open\n");
        return -1;
    }

    offset = lseek(fd, offset, SEEK_END);

    if(offset == -1) {
        printf("fail to lseek\n");
        return -1;
    }

    printf("offset : %d\n", offset);

    return 0;
}
