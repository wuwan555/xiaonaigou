#pragma once
#include"stdio.h"
#include"assert.h"
#include"string.h"

enum SEX
{
	Man,
	Women,
};

typedef struct Addressinfo
{
	char _name[24];
	char _tel[24];
	char _age;
	enum SEX _sex;
}Addressinfo;
#define MAX_SIZE 100
typedef struct Addressbook
{
	Addressinfo _AIarray[MAX_SIZE];
	size_t _size;
} Addressbook;  
void Addressbookinit(Addressbook* pbook);
void AddressbookAdd(Addressbook* pbook, Addressinfo* pinfo);
void AddressBookDel(Addressbook* pbook, const char* name);
Addressinfo* AddressBookFind(Addressbook* pbook, const char* name);