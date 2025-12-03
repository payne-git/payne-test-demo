#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define	MQTT_LENGTH_16		16
#define	MQTT_LENGTH_32		32
#define	MQTT_LENGTH_33		33
#define	MQTT_LENGTH_40		40
#define	MQTT_LENGTH_50		50
#define	MQTT_LENGTH_64		64
#define	MQTT_LENGTH_65		65
#define	MQTT_LENGTH_128		128

enum mqtt_debug_log_level {
	MQTT_LEVEL_ERROR = 0,
	MQTT_LEVEL_WARNING,
	MQTT_LEVEL_LOG,
	MQTT_LEVEL_DEBUG,
	MQTT_LEVEL_DEBUG_API,
};

#define MQTT_LEVEL_CURRENT MQTT_LEVEL_DEBUG_API

#define XDEBUG_DBG(level, format, ...) \
	do { \
		if (level <= MQTT_LEVEL_CURRENT) { \
			struct tm tmp; \
			time_t now = time(NULL); \
			if (localtime_r(&now, &tmp) != NULL) { \
				fprintf(stdout, "[ FILE:%s LINE:%d FUNC:%s] "format, \
				__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
				fflush(stdout); \
			} \
		} \
	} while (0)


#define DATE_CMD "cfgtool system time set date %s clock %s timezone %s"
int set_system_date(char *timestamp)
{
	char cmd_buf[MQTT_LENGTH_128];
	char date_buf[MQTT_LENGTH_32];
	char clock_buf[MQTT_LENGTH_32];
	char timezone_buf[MQTT_LENGTH_16];
	char *find_date = "T";
	char *find_clock_1 = "+";
	char *find_clock_2 = "-";
	char *find_timezone = ":";
	char *date_end = NULL;
	char *clock_end = NULL;
	char *timezone_end = NULL;
	int date_len = 0;
	int clock_len = 0;
	int timezone_len = 0;

	memset(cmd_buf, 0, sizeof(cmd_buf));
	memset(date_buf, 0, sizeof(date_buf));
	memset(clock_buf, 0, sizeof(clock_buf));
	memset(timezone_buf, 0, sizeof(timezone_buf));
	date_end = strstr(timestamp, find_date);
	if (date_end) {
		date_len = date_end - timestamp;
		strncpy(date_buf, timestamp, date_len);
		XDEBUG_DBG(MQTT_LEVEL_DEBUG, "date_buf:%s.\n", date_buf);

		date_end += sizeof(*find_date);
		clock_end = strstr(date_end, find_clock_1);
		if (clock_end) {
			clock_len = clock_end - date_end;
			strncpy(clock_buf, date_end, clock_len);
			XDEBUG_DBG(MQTT_LEVEL_DEBUG, "clock_buf:%s.\n", clock_buf);
			
			//clock_end += sizeof(*find_clock_1);
			timezone_end = strstr(clock_end, find_timezone);
			if (timezone_end) {
				timezone_len = timezone_end - clock_end;
				strncpy(timezone_buf, clock_end, timezone_len);
				sprintf(cmd_buf, DATE_CMD, date_buf, clock_buf, timezone_buf);
			}
		} else {
			clock_end = strstr(date_end, find_clock_2);
			if (clock_end) {
				clock_len = clock_end - date_end;
				strncpy(clock_buf, date_end, clock_len);
				XDEBUG_DBG(MQTT_LEVEL_DEBUG, "clock_buf:%s.\n", clock_buf);
				
				//clock_end += sizeof(*find_clock_2);
				timezone_end = strstr(clock_end, find_timezone);
				if (timezone_end) {
					timezone_len = timezone_end - clock_end;
					strncpy(timezone_buf, clock_end, timezone_len);
					sprintf(cmd_buf, DATE_CMD, date_buf, clock_buf, timezone_buf);
				}
			}
		}
	}
	
	XDEBUG_DBG(MQTT_LEVEL_DEBUG, "set date cmd:%s.\n", cmd_buf);
#if 0
	if (strlen(cmd_buf) != 0) {
		system(cmd_buf);
	}
#endif
	return 0;
}


int main()
{
    char *ptr = "2024-08-08T15:49:12+08:00";

    set_system_date(ptr);

    printf("end\n");
    
    return 0;
}

