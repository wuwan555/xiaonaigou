#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include"stdlib.h"
//int main()
//{
//	int a, b;
//	int str[]="sad";
//}
//int main()
//{
//	int *p = malloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	
//	int* ptr = NULL;
//	int num ;
//	printf("��Ҫ��������ڴ�ռ䣺");
//	scanf("%d", &num);
//	ptr = (int*)malloc(num*sizeof(int));
//	//if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < num; i++)
//	//	{
//	//		*(ptr + i) = 0;
//	//	}
//	
//	free(ptr);//�ͷŵ��������Ķ�̬�ռ�
//	ptr = NULL;
//	return 0;
//}
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
int main()
{
	int *ptr = malloc(100);//����һ�οռ�
	if (ptr != NULL)
	{
		;
	}
	else
	{
		exit(EXIT_FAILURE);
	}

	ptr = realloc(&ptr, 1000);
	int*p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	free(ptr);
	return 0;
}