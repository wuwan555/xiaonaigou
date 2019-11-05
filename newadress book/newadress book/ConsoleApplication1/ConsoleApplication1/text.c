#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	AddressInfo info1 = { "张三", "110", 18, Man };
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "小王", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "小李", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	AddressBookSave(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);
	AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);
	AddressBookDestoty(&addressbook);
}


//int main()
//{
//	TestAddressBook();
//
//	return 0;
//}
int main()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook); 
	AddressInfo info1 = { "张三", "110", 18, Man };
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "小王", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "小李", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	//AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookSave(&addressbook, "addressfile.txt");
	printf("==============================\n");
	int option = 0;
	
	do{
		printf("1.添加通讯录信息，2.查找通讯录信息\n");
		printf("3.删除通讯录信息，4.修改通讯录信息\n");
		printf("5.保存通讯录到文件，6.读取通讯录信息\n");
		printf("7.打印通讯录信息，-1.退出\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printf("请依次输入姓名,电话,年龄,性别：\n");
			AddressInfo info;
			scanf("%s",info._name);
			scanf("%s", info._tel);
			scanf("%d", &info._age);
			char sex[10];
			scanf("%s", &sex);
			if (strcmp(sex, "男"))
			info._sex == 0;
			else
				info. _sex == 1;
			AddressBookAdd(&addressbook, &info);
		}
		else if (option == 2)
		{
			char name[20];
			printf("请输入查找联系人的姓名：\n");
			scanf("%s", name);
			AddressInfo *ret = AddressBookFind(&addressbook, name);
			if (ret == NULL)
			{
				printf("查无此人\n");
			}
			else
			{
				printf("姓名：%s", ret->_name);
				printf("电话：%s", ret->_tel);
				printf("年龄：%d", ret->_age);
				printf("性别：%d", ret->_sex);
			}
		}
		else if (option == 3)
		{
			char name[20];
			printf("请输入要删除的联系人的姓名：\n");
			scanf("%s", name);
			AddressBookDel(&addressbook, name);

		}
		else if (option == 4)
		{
			char name[20];
			printf("请输入修改联系人的信息：\n");
			scanf("%s", name);
			AddressInfo *ret = AddressBookFind(&addressbook, name);
			if (ret == NULL)
			{
				printf("查无此人");
			}
			else
			{
				printf("请输入修改联系人的电话:\n");
				scanf("%s", ret->_tel);
				
			}
		}
		else if (option == 5)
		{
			AddressBookSave(&addressbook, "addressfile.bin");
		}
		else if (option == 6)
		{
			addressbook._size = 0;
			AddressBookLoad(&addressbook, "addressfile.bin");
		}
		else if (option == 7)
		{
			AddressBookPrint(&addressbook);
		}


	} while (option >= 0);
	printf("==============================");
	return 0;
}