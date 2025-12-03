#include <stdio.h>
#include <unistd.h>
#include <string.h>


void main()
{
    int i = 0;
    char proc[101];
    memset(proc, 0, 101);

    while (i <= 100) {
        printf("[%-100s] %d%%\r", proc, i);
        //printf("\033[1A");
        //printf("\033[K");
        proc[i] = '=';
        if (i != 100) {
            //printf("\033[1A");
            proc[i+1] = '>';
        }
        fflush(stdout);
        usleep(80000);
        i++;
    }
    puts("");

    return;
}
