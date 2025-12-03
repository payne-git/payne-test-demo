#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void hex_str_to_byte_array(char *source, char *dest, int sourceLen) {
	int i;
	unsigned char highByte, lowByte;

	for (i = 0; i < sourceLen; i += 2) {
		highByte = toupper(source[i]);
		lowByte = toupper(source[i + 1]);

		if (highByte > 0x39)
				highByte -= 0x37;
		else
				highByte -= 0x30;

		if (lowByte > 0x39)
				lowByte -= 0x37;
		else
				lowByte -= 0x30;
		//printf("highByte:%c, lowByte:%c.\n", highByte, lowByte);
		dest[i / 2] = (highByte << 4) | lowByte;
		//printf("dest[%d]:%c.\n", i/2, dest[i / 2]);
	}
	printf("dest:%s.\n", dest);
}




int main(int argc, char *argv[]) {
	char array[1024] = {0};
	if (argc <= 1) {
		puts("Please input hex-str");
		return -1;
	}
	printf("argv[1]:%s, strlen(argv[1]):%lu\n", argv[1], strlen(argv[1]));
	hex_str_to_byte_array(argv[1], array, strlen(argv[1]));
	
	printf("array:%s.\n", array);

	return 0;
}