#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void AddressBookInit(AddressBook* pbook)
{
	assert(pbook);
	pbook->_size = 0;
	pbook->_capacity = 2;
	pbook->_AIArray = (AddressInfo*)malloc(sizeof(AddressInfo)* 2);
	assert(pbook->_AIArray);
}
void AddressBookDestoty(AddressBook *pbook)//空间的释放
{
	assert(pbook);
	free(pbook);
	pbook->_AIArray = NULL;
	pbook->_size = pbook->_capacity = 0;
}

void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo)
{
	assert(pbook);

	if (pbook->_size == pbook->_capacity)
	{
		// 空间满了，进行扩容
		pbook->_AIArray = realloc(pbook->_AIArray, pbook->_capacity * 2 * sizeof(AddressInfo));//扩容二倍
		pbook->_capacity *= 2;
	}

	strcpy(pbook->_AIArray[pbook->_size]._name, pinfo->_name);
	strcpy(pbook->_AIArray[pbook->_size]._tel, pinfo->_tel);
	pbook->_AIArray[pbook->_size]._age = pinfo->_age;
	pbook->_AIArray[pbook->_size]._sex = pinfo->_sex;
	pbook->_size++;
}

void AddressBookSave(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "w");//文件的写入
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fputs(pbook->_AIArray[i]._name, fp);
		fputc('\n', fp);
		char telstr[20];
		itoa(pbook->_AIArray[i]._tel, telstr,10);
		fputs(pbook->_AIArray[i]._tel, fp);
		fputc('\n', fp);
	}
	AddressInfo end;
	end._age = -1;
	fwrite(&end, sizeof(AddressInfo), 1, fp);
}

void AddressBookLoad(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "r");//文件的读入
	AddressInfo info;

	while (1)
	{
		info._name[0] = '\0';
		info._tel[0] = '\0';
		info._age = 0;
		fscanf("%s%s%d",info._name,info._tel,info._age);
		if (info._age == -1)
		{
			break;
		}
		else
		{
			AddressBookAdd(pbook, &info);
		}
	}
}

void AddressBookDel(AddressBook* pbook, const char* name)
{
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		if (strcmp(pbook->_AIArray[i]._name, name) == 0)
		{
			while (i < pbook->_size - 1)
			{
				strcpy(pbook->_AIArray[i]._name, pbook->_AIArray[i + 1]._name);//把后一个信息拷贝到目标对象中去，进行覆盖。
				strcpy(pbook->_AIArray[i]._tel, pbook->_AIArray[i + 1]._tel);
				pbook->_AIArray[i]._age = pbook->_AIArray[i + 1]._age;
				pbook->_AIArray[i]._sex = pbook->_AIArray[i + 1]._sex;
				++i;
			}
			pbook->_size--;
			break;
		}
	}
}

AddressInfo* AddressBookFind(AddressBook* pbook, const char* name)
{
	assert(pbook);
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		if (strcmp(pbook->_AIArray[i]._name , name)==0)//使用库函数进行比较
		{
			return &pbook->_AIArray[i];
		}
	}
	return NULL;
}

void AddressBookPrint(AddressBook* pbook)
{
	assert(pbook);

	for (size_t i = 0; i < pbook->_size; ++i)
	{
		//printf("======================================\n");
		printf("name:%s\n", pbook->_AIArray[i]._name);
		printf("tel:%s\n", pbook->_AIArray[i]._tel);
		printf("age:%d\n", pbook->_AIArray[i]._age);
		printf("sex:%d\n", pbook->_AIArray[i]._sex);
		printf("======================================\n");
		printf("\n");

	}
}