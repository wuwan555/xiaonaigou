#define _CRT_SECURE_NO_WARNINGS 1
#include"AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;
	AddressBookInit(&addressbook);
	AddressInfo info1 = { "����", "110", 18, Man };
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "С��", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "С��", "111", 19, Man };
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
	AddressInfo info1 = { "����", "110", 18, Man };
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "С��", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "С��", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);
	//AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookSave(&addressbook, "addressfile.txt");
	printf("==============================\n");
	int option = 0;
	
	do{
		printf("1.���ͨѶ¼��Ϣ��2.����ͨѶ¼��Ϣ\n");
		printf("3.ɾ��ͨѶ¼��Ϣ��4.�޸�ͨѶ¼��Ϣ\n");
		printf("5.����ͨѶ¼���ļ���6.��ȡͨѶ¼��Ϣ\n");
		printf("7.��ӡͨѶ¼��Ϣ��-1.�˳�\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printf("��������������,�绰,����,�Ա�\n");
			AddressInfo info;
			scanf("%s",info._name);
			scanf("%s", info._tel);
			scanf("%d", &info._age);
			char sex[10];
			scanf("%s", &sex);
			if (strcmp(sex, "��"))
			info._sex == 0;
			else
				info. _sex == 1;
			AddressBookAdd(&addressbook, &info);
		}
		else if (option == 2)
		{
			char name[20];
			printf("�����������ϵ�˵�������\n");
			scanf("%s", name);
			AddressInfo *ret = AddressBookFind(&addressbook, name);
			if (ret == NULL)
			{
				printf("���޴���\n");
			}
			else
			{
				printf("������%s", ret->_name);
				printf("�绰��%s", ret->_tel);
				printf("���䣺%d", ret->_age);
				printf("�Ա�%d", ret->_sex);
			}
		}
		else if (option == 3)
		{
			char name[20];
			printf("������Ҫɾ������ϵ�˵�������\n");
			scanf("%s", name);
			AddressBookDel(&addressbook, name);

		}
		else if (option == 4)
		{
			char name[20];
			printf("�������޸���ϵ�˵���Ϣ��\n");
			scanf("%s", name);
			AddressInfo *ret = AddressBookFind(&addressbook, name);
			if (ret == NULL)
			{
				printf("���޴���");
			}
			else
			{
				printf("�������޸���ϵ�˵ĵ绰:\n");
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