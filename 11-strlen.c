#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


static struct tos_default_service{
	char		*name;
	short		protocol;
	short		port;
	char		*comment;
} ds_list[] = {
	{"IP",		0x0800,	0,	"Internet Protocol packet"},
	{"ARP",		0x0806,	0,	"Address Resolution packet"},
	{"LOOP",	0x0060,	0,	"Ethernet Loopback packet"},
	{"XEROX_PUP",		0x0200,	0,	"Xerox PUP packet"},
	{"PUPAT",	0x0201,	0,	"Xerox PUP Addr Trans packet"},
	{NULL,			0,	0,	NULL}
};


int main()
{
    //time_t t;
    char ct[256];
	int m = 0;
	for (int i = 0; ds_list[i].name != NULL; i++) {
		m = strlen(ds_list[i].name);
		printf("m:%d\n", m);
	}
	
#if 0
    time(&t);
    memset(ct, 0, 256);
    strncpy(ct, (char *)ctime(&t), strlen((char *)ctime(&t)) - 1);

    printf("ctime(&t) : %s", ctime(&t));

    printf("strlen((char *)ctime(&t)) : %u\n", strlen((char *)ctime(&t)));
#endif
    return 0;
}

