#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
 void paixu(int ch[])
{
	 int i = 0;
	 int legthen = 0;
	legthen = sizeof(ch) / sizeof(ch[0]);
	int j = legthen - 1;
	int temp = 0;
	while (i<j)
	{

		if ((ch[i] & 1) == 1)
		{
			i++;
			continue;
		}
		if ((ch[j] & 1) == 0) 
		{
			j++;
			continue;
		}
		temp = ch[i];
		ch[i] = ch[j];
		ch[j] = temp;
		i++;
		j--;
	}
}
 int main()
 {
	 int be[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	 scanf("%d", &be[9]);
	 paixu(be[9]);
	 printf("%d", be[9]);
	 return 0;
 }
 //void Sort(int num[], int len) 
 {
	 for (int i = 0; i < len - 1; ++i) 
	 {
		 for (int j = 0; j < len - i - 1; ++j) 
		 {
			 if (num[j] % 2 == 0 && num[j + 1] % 2 != 0)
			 {
				 int tmp = num[j];
				 num[j] = num[j + 1];
				 num[j + 1] = tmp;
			 }
		 }
	 }
 }
 //int main()
 {
	 int num[] = { 3, 4, 7, 8, 12, 1 };
	 Sort(num, sizeof(num) / sizeof(int));
	 for (int i = 0; i < sizeof(num) / sizeof(int); ++i)
	 {
		 printf("%d ", num[i]);
	 }
	 printf("\n");
	 system("pause");
	 return 0;
 }
 