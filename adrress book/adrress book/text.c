#define _CRT_SECURE_NO_WARNINGS 1
#include "address.h"

void TestAddressbook()
{
	Addressbook Addressbook;
	Addressbookinit(&Addressbook);
	Addressinfo info1 = { "张三", "110", 18, Man };
	AddressbookAdd(&Addressbook, &info1);

	Addressinfo info2 = { "李四", "111", 19, Man };
	AddressbookAdd(&Addressbook, &info2);
}

int main()
{
	TestAddressbook();

	return 0;
}