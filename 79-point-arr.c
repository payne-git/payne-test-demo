#include <stdio.h>
#include <string.h>

//gcc 79-point-arr.c -DTEST_INT -DTEST_CHAR

int main()
{
#ifdef TEST_INT
    int i = 2024, j = 2023, k = 2022;
    int a[3];
    int b[5] = {2,7,3,9,12};
    int two_point[3][5] = {{9,7,5,3,1}, {8,6,4,2,0}, {1,4,7,9,11}};
    int *p = &two_point[0][0];
	int **q;
	int *m[3];	//指针数组
	int (*n)[5];	//数组指针，n <=> two_point[3]

    //two_point[1] = q;	//编译报错，数组头指针属于常量，不能被赋值
	memcpy(two_point[1], b, sizeof(b));

    a[0] = i;
    a[1] = j;
    a[2] = k;
	
	m[0] = &i;
	m[1] = &j;
	m[2] = &k;
	
	n = two_point;
	q = two_point;	//编译告警，类型不匹配

    for (int x = 0; x < 3; x++)
        printf("a[%d]:%d\n", x, a[x]);
    for (int x = 0; x < 5; x++)
        printf("b[%d]:%d\n", x, b[x]);
    for (int x = 0; x < 5; x++)
        printf("two_point[1][%d]:%d\n", x, two_point[1][x]);
    for (int x = 0; x < 3; x++)
        printf("*m[%d]:%d\n", x, *m[x]);
    for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 5; y++) {
			printf("n[%d][%d]:%d\n", x, y, n[x][y]);
		}
	}

	printf("*(a + 1):%d \n", *(a + 1));	//a[1]
	printf("*a + 1:%d \n", *a + 1);	//a[0] + 1
	printf("*(p + 1):%d \n", *(p + 2));	//p[2] <==> two_point[0][2]
	printf("*(two_point + 1):%d \n", **(two_point + 2));	//two_point[2][0]
	printf("two_point[1][3]:%d, *(two_point[1]+3):%d, *(*(two_point+1)+3):%d.\n", two_point[1][3], *(two_point[1]+3), *(*(two_point+1)+3));
	printf("n[1][3]:%d, *(n[1]+3):%d, *(*(n+1)+3):%d.\n", n[1][3], *(n[1]+3), *(*(n+1)+3));
	printf("q[1][4]:%d.\n", q[1][4]);	//报段错误，为啥不理解
#endif

#ifdef TEST_CHAR
#endif
	return 0;
}
