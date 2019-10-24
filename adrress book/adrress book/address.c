#define _CRT_SECURE_NO_WARNINGS 1
#include "address.h"

void Addressbookinit(Addressbook* pbook)
{
	assert(pbook);
	pbook->_size = 0;
	for (size_t i = 0; i < MAX_SIZE; ++i)
	{
		pbook->_AIarray[i]._name[0] = '\0';
		pbook->_AIarray[i]._tel[0] = '\0';

		pbook->_AIarray[i]._age = 0;
		pbook->_AIarray[i]._sex = Man;
	}
}

void AddressbookAdd(Addressbook* pbook, Addressinfo* pinfo)
{
	assert(pbook);
	assert(pinfo);

	if (pbook->_size == MAX_SIZE)
	{
		printf("Address Book Full\n");
	}
	else
	{
		strcpy(pbook->_AIarray[pbook->_size]._name, pinfo->_name);
		strcpy(pbook->_AIarray[pbook->_size]._tel, pinfo->_tel);
		pbook->_AIarray[pbook->_size]._age = pinfo->_age;
		pbook->_AIarray[pbook->_size]._sex = pinfo->_sex;
		pbook->_size++;
	}
}

void AddressbookDel(Addressbook* pbook, const char* name)
{}

Addressinfo* AddressbookFind(Addressbook* pbook, const char* name)
{
	return NULL;
}



