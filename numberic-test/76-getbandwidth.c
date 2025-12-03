#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MQTT_LENGTH_64 64
#define MQTT_LENGTH_128 128

#define CMD_GET_INTERFACE_BANDWIDTH     "cfgtool monitor dev interface-total show | grep %s %s"
#define CMD_GET_INTERFACE_DOWNBANDWIDTH     " | awk '{print $4}' "
#define CMD_GET_INTERFACE_UPBANDWIDTH       " | awk '{print $5}' "


int main()
{
	FILE *fp = NULL;
	char cmd_result[MQTT_LENGTH_64];
	char cmd_buf[MQTT_LENGTH_128];
	char *ptr = NULL;
	char bandwidth[MQTT_LENGTH_64];
	long upbandwidth = 0;

	sprintf(cmd_buf, CMD_GET_INTERFACE_BANDWIDTH, "eth0", CMD_GET_INTERFACE_DOWNBANDWIDTH);
	printf("cmd_buf:%s\n", cmd_buf);
	fp = popen(cmd_buf, "r");
	if(fp == NULL){
		printf("%s-%d: popen error\n", __FUNCTION__, __LINE__);
		return -1;
	}
	if (fgets(cmd_result, MQTT_LENGTH_64, fp)) {
		strncpy(bandwidth, cmd_result, strlen(cmd_result) - 0);
		printf("bandwidth:%s\n", bandwidth);
		upbandwidth = atol(bandwidth);
	}
	fclose(fp);
	printf("the interface eth0 upbandwidth is %ld\n", upbandwidth);

	return 0;
}

