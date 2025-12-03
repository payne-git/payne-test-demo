#include <stdio.h>
#include <time.h>
#include <sys/time.h>




int main ()
{
    time_t now = time(NULL);
    struct timeval tv;
    long long microseconds = 0;

    gettimeofday(&tv, NULL);

    microseconds = tv.tv_sec * 1000000LL + tv.tv_usec;
    
    printf("now:%ld\n", now);

    printf("microseconds:%lld\n", microseconds);

    return 0;
}

