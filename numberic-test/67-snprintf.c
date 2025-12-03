#include <stdio.h>
#include <string.h>



int main ()
{
    char buf[4096] = "";

    char tmp[256];
    
    snprintf(tmp, 256, "network bond add id 0 load-balance active-backup\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 0 dev eth2\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 0 dev eth3\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond id 0 active is eth3\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond add id 1 load-balance active-backup\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 1 dev eth4\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 1 dev eth5\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond id 1 active is eth5\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond add id 2 load-balance active-backup\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 2 dev eth6\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 2 dev eth7\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond id 2 active is eth7\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond add id 3 load-balance active-backup\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 3 dev eth8\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond join id 3 dev eth9\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    snprintf(tmp, 256, "network bond id 3 active is eth9\n");
    strcat(buf, tmp);
    printf("tmp:%s, strlen(tmp):%lu\n", tmp, strlen(tmp));

    printf("buf:%s\n", buf);

    return 0;
}

