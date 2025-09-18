#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define CHARSET_LEN		62
#define UUID_LENGTH		16

static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 



char* generate_uuid() {
	char uuid[UUID_LENGTH + 1];
	unsigned int idx = 0;
	unsigned int random_value;
    int urandom_fd = open("/dev/urandom", O_RDONLY);

    if (urandom_fd == -1) {
        perror("Failed to open /dev/urandom");
        exit(EXIT_FAILURE);
    }

	while (idx < UUID_LENGTH) {
		if (read(urandom_fd, &random_value, sizeof(random_value)) != sizeof(random_value)) {
			perror("Failed to read from /dev/urandom");
			close(urandom_fd);
			exit(EXIT_FAILURE);
		}

		// 将读取的随机值转化为字符集内的索引，确保它落在有效范围内
		printf("idx:%d\n", idx);
		uuid[idx++] = charset[random_value % CHARSET_LEN];
		//random_value /= CHARSET_LEN;
		if (idx >= UUID_LENGTH)
			break;
	}
	uuid[UUID_LENGTH] = '\0';
	close(urandom_fd);

    return strdup(uuid); // 注意：这里使用strdup返回一个新的字符串，需要手动free
}

int main() {
    char* uuid = generate_uuid();
    printf("Generated UUID: %s\n", uuid);
    free(uuid); // 不要忘记释放内存
    return 0;
}