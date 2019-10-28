#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 50
int fun(int n)
{
	int st[MAX][2], top = 0;
	st[top][0] = n; st[top][1] = 0;
	do
	{
		if (st[top][0] == 1)
			st[top][1] = 1;
		if (st[top][0] > 1 && st[top][1] == 0)
		{
			top++;
			st[top][0] = st[top - 1][0] - 1;
			st[top][1] = 0;

		}
		if (st[top][1] != 0)
		{
			st[top - 1][1] = st[top][1] * st[top - 1][0];
			top--;
		}
		
	} while (top > 0);
	return st[0][1];
}
void main()
{
	int n;
	printf("input n:(<50)\n");
	scanf("%d", &n);
	printf("(n!)=%d\n", fun(n));
}