#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 函数用于格式化时间
char* format_time_iso8601(char* buf, size_t sz) {
    time_t now = time(NULL);
    struct tm tm_info;
    localtime_r(&now, &tm_info);

    // 格式化日期时间部分
    strftime(buf, sz, "%Y-%m-%dT%H:%M:%S", &tm_info);

    // 计算时区偏移
    int offset_minutes = tm_info.tm_gmtoff / 60;
    int hours = offset_minutes / 60;
    int minutes = abs(offset_minutes % 60); // 时区偏移可以是正也可以是负

    // 添加时区偏移部分，注意处理正负号
    sprintf(buf + strlen(buf), "%c%02d:%02d", (offset_minutes >= 0) ? '+' : '-', hours, minutes);

    return buf;
}

int main() {
    char time_str[100];
    printf("Current ISO 8601 Time: %s\n", format_time_iso8601(time_str, sizeof(time_str)));
    return 0;
}