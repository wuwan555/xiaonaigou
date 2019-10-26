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
//		//使用空间
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
//	printf("你要申请多大的内存空间：");
//	scanf("%d", &num);
//	ptr = (int*)malloc(num*sizeof(int));
//	//if (NULL != ptr)//判断ptr指针是否为空
//	//{
//	//	int i = 0;
//	//	for (i = 0; i < num; i++)
//	//	{
//	//		*(ptr + i) = 0;
//	//	}
//	
//	free(ptr);//释放掉这段申请的动态空间
//	ptr = NULL;
//	return 0;
//}
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
int main()
{
	int *ptr = malloc(100);//开辟一段空间
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