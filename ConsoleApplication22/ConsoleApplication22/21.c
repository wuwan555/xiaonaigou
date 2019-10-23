#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include"assert.h"
#if 0
void sleclt(int *arr,int len)
{
	int i = 0; int j = 0; 
	for (i = 0; i<len; i++)
	{
		int k = 0;
		for (j = 0; j < len; j++)
		{
			
			if (arr[i]==arr[j])
			{
				k++;
			}
		}
		if (k == 1)
		{
			printf("%d\n", arr[i]);
		}
	}
}
int main()
{
	int arr[] = { 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	sleclt(arr,len);
}
#endif
//void buywater(int m)
//{
//	int sum = m;
//	while (m > 1)
//	{
//		int k = m / 2;
//		int sy = m % 2;
//		m = k + sy;
//		sum += k;
//	}
//	printf("%d", sum);
//	
//}
//int main()
//{
//	int m = 0;
//	printf("请输入你有多少钱：");
//	scanf("%d", &m);
//	buywater(m);
//}
#if 0
char *my_strcpy(char *dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	int len = strlen(src); int i;
	for (i = 0; i < len + 1; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
}
#endif
//int main()
//{
//	char str1[20], str2[] = "dfsdsf";
//	my_strcpy(str1, str2);
//	printf("%s", str1);
//
//}
char *my_strcat(char *dst, const char*str)
{
	char* ret = dst;
	assert(dst != NULL);
	assert(str != NULL);
	while (*dst)
	{
		dst++;
	}
	while ((*dst++ = *str++))
	{
		;
	}
	return ret;
}
void main()
{
	char str1[30] = "hello";
	char str2[] = "world";
	my_strcat(str1, str2);
	printf("%s", str1);
}