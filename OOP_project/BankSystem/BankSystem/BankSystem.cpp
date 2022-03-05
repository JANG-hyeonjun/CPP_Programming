#include "BankSystem.h"


int main(void)
{
	int choice = 0;
	while (1)
	{
		ShowMenu();
		std::cout << "����: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccinfo();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "Illegal selection.." << std::endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	std::cout << "----------------Menu------------------" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. ��  ��" << std::endl;
	std::cout << "3. ��  ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�̸�: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int id;
	int money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�Աݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			std::cout << "�ԱݿϷ�" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "����� ���� ���� �Դϴ�" << std::endl;
}
void WithdrawMoney(void)
{
	int id;
	int money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "��ݾ�: "; std::cin >> money;
	
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				std::cout << "�ܾ׺���" << std::endl << std::endl;
				return;
			}
			accArr[i].balance -= money;
			std::cout << "��ݿϷ�" << std::endl;
		}
	}
	std::cout << "����� ���� ���� �Դϴ�." << std::endl;
}
void ShowAllAccinfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "����ID: " << accArr[i].accID << std::endl;
		std::cout << "�� ��: " << accArr[i].cusName << std::endl;
		std::cout << "�� ��: " << accArr[i].balance << std::endl << std::endl;
	}
}