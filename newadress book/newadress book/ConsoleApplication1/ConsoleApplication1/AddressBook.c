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
void AddressBookDestoty(AddressBook *pbook)
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
		pbook->_AIArray = realloc(pbook->_AIArray, pbook->_capacity * 2 * sizeof(AddressInfo));
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
	FILE* fp = fopen(filename, "w");
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&(pbook->_AIArray[i]), sizeof(AddressInfo), 1, fp);
	}
	AddressInfo end;
	end._age = -1;
	fwrite(&end, sizeof(AddressInfo), 1, fp);
}

void AddressBookLoad(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "r");
	AddressInfo info;

	while (1)
	{
		fread(&info, sizeof(AddressInfo), 1, fp);
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
				strcpy(pbook->_AIArray[i]._name, pbook->_AIArray[i + 1]._name);
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
		if (strcmp(pbook->_AIArray[i]._name , name)==0)
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