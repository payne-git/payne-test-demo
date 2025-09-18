#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MQTT_LENGTH_16 16

#define CMD_BASE "cfgtool network interface %s show configuration %s"
#define CMD_L2_L3 " | grep \"no switchport\""
#define CMD_L2_L4 ""

int main()
{
    FILE *fp = NULL;
    char cmd_result[MQTT_LENGTH_16];
    char cmd[128];
    char cmd1[128];
    sprintf(cmd, CMD_BASE, "eth1", CMD_L2_L3);
    printf("cmd:%s\n", cmd);
    sprintf(cmd1, CMD_BASE, "", "123");
    printf("cmd1:%s\n", cmd1);
    fp = popen(cmd, "r");
    //fp = popen("echo $PWD", "r");
    if(fp == NULL){
        printf("%s-%d: popen error\n", __FUNCTION__, __LINE__);
        return -1;
    }
    if (fgets(cmd_result, MQTT_LENGTH_16, fp)) {
        cmd_result[strlen(cmd_result) - 1] = '\0';
        printf("cmd_result:%s\n", cmd_result);
    } else {
        printf("switchport\n");
    }
    fclose(fp);
    return 0;
}

