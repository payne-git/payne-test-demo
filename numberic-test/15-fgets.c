#include <stdio.h>
#include <string.h>


int main()
{
	int num = 0;
    char tmpbuf[64] = "hello world nihao sheet abcde fghij klmno pqrst uvwxy z1234";
	char tmpbuf2[64] = {0};
	char tmpbuf3[64] = "hello world nihao sheet abcde fghij klmno pqrst uvwxy z1234";
	FILE *fp = fopen("./8.sh","r");

    printf("start\n");

    while (fgets(tmpbuf2, sizeof(tmpbuf2), fp)) {
        printf("%d %s.", num++, tmpbuf2);
    }
	printf("tmpbuf:%s.\n", tmpbuf);
	strcpy(tmpbuf, tmpbuf2);
	printf("tmpbuf:%s.\n", tmpbuf);

	printf("tmpbuf3:%s.\n", tmpbuf3);
	strncpy(tmpbuf3, tmpbuf2, strlen(tmpbuf2));
	printf("tmpbuf3:%s.\n", tmpbuf3);

    if(fp)
        fclose(fp);

    printf("end\n");

    return 0;
}
