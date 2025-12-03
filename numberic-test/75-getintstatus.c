#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MQTT_LENGTH_64 64

#define CMD_BASE "cfgtool network interface %s show %s"
#define CMD_GET_INTERFACE_STATUS " | grep \"Link status:\""

int main()
{
    FILE *fp = NULL;
    char cmd_result[MQTT_LENGTH_64];
    char cmd[128];
    char cmd1[128] = "not established";
    char *ptr = NULL;
    //char inter[16] = "vlan.0003";
    //char inter[] = "ipsec3";
    char inter[] = "veth0.03";
    sprintf(cmd, CMD_BASE, inter, CMD_GET_INTERFACE_STATUS);
    printf("cmd:%s\n", cmd);
    fp = popen(cmd, "r");
    //fp = popen("echo $PWD", "r");
    if(fp == NULL){
        printf("%s-%d: popen error\n", __FUNCTION__, __LINE__);
        return -1;
    }
    if (fgets(cmd_result, MQTT_LENGTH_64, fp)) {
        //cmd_result[strlen(cmd_result) - 1] = '\0';
        printf("cmd_result:%s\n", cmd_result);
        ptr = strstr(cmd_result, cmd1);
        if (ptr)
            puts("Current the interface eth1 is down");
        else
            puts("Current the interface eth1 is up");
    } else {
        printf("switchport\n");
    }
    fclose(fp);
    return 0;
}

