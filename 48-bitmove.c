#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



int main(int argc, char* argv[])
{
    char ip[] = "10.10.10.0";
    char gw[] = "10.10.0.0";
    char *fib = NULL;

    long l_ip = 0;
    long l_gw = 0;
    long index = 0;

    fib = malloc(128);
    if (!fib)
        return -1;

    inet_pton(AF_INET, ip, &l_ip);
    inet_pton(AF_INET, gw, &l_gw);

    index = l_ip ^ l_gw;

    inet_ntop(AF_INET, &index, fib, 128);

    printf("L:%d, F:%s, ip:%s, l_ip:%ld\n", __LINE__, __FUNCTION__, ip, l_ip);
    printf("L:%d, F:%s, gw:%s, l_gw:%ld\n", __LINE__, __FUNCTION__, gw, l_gw);
    printf("L:%d, F:%s, fib:%s, index:%ld\n", __LINE__, __FUNCTION__, fib, index);
    if (argc > 1 && argv[1]) {
        printf("argv[1]:%s\n", argv[1]);
        printf("L:%d, F:%s, index >> %d : %ld\n", __LINE__, __FUNCTION__, atoi(argv[1]), index >> atoi(argv[1]));
    }

    free(fib);
    fib = NULL;

    return 0;
}

