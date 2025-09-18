#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    char buf[] = "veth0.01";
	char null_buf[32];
    int ret = 0;
    
	memset(null_buf, 0, sizeof(null_buf));
	
    ret = strncmp(buf, "eth" ,3);

    printf("buf:%s, ret : %d\n", buf, ret);

	ret = strcmp(null_buf, "eth");

    printf("null_buf:%s, ret : %d\n", null_buf, ret);
	
	return 0;
}
