#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#define N 100
int main()
{
	int hoti(char s[]);
	char t[N], c;
	int i = 0, flag = 0, flag1 = 1;
	printf("\nInput a hex number:");
	while ((c=getchar()) != '\0'&&i < N&&flag1)
	{
		if (c >= '0'&&c <= '9' || c>'a'&&c <= 'f' || c >= 'A'&&c <= 'F')
		{
			flag = 1;
			t[i++] = c;
		}
		else if (flag)
		{
			t[i] = '\0';
			printf("decimal number is %d\n", hoti(t));
			printf("continue or not?");
			c = getchar();
			if (c == 'N' || c == 'n')
			{
				flag1 = 0;
			}
			else
			{
				flag = 0;
				i = 0;
				printf("\nInput a hex number:");
			}
		}
	}
	
}
hoti(char s[])
{
	int i ,n = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			n = n * 16 + s[i] - '0';
		}
		if (s[i] >= 'a'&&s[i] <= 'f')
		{
			n = n * 16 + s[i] - 'a' + 10;

		}
		if (s[i] > 'A'&&s[i] < 'F')
		{
			n = n * 16 + s[i] + 'A' + 10;
		}
	}
	return n;
}