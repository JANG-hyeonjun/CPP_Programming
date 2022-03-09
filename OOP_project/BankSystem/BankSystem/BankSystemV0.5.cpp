#include "BankSystemV0.5.h"




int main(void)
{
	int choice = 0;
	AccountHandler* manager = new AccountHandler;
	
	while (1)
	{
		manager->ShowMenu();
		std::cout << "����: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			manager->MakeAccount();
			break;
		case DEPOSIT:
			manager->DepositMoney();
			break;
		case WITHDRAW:
			manager->WithdrawMoney();
			break;
		case INQUIRE:
			manager->ShowAllAccinfo();
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "Illegal selection.." << std::endl;
		}
	}
	delete manager;
	return 0;
}


AccountHandler::AccountHandler(): accNum(0)
{

}

AccountHandler::~AccountHandler()
{

	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}


void AccountHandler::ShowMenu(void) const
{
	std::cout << "----------------Menu------------------" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. ��  ��" << std::endl;
	std::cout << "3. ��  ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�̸�: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int id;
	int money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�Աݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			std::cout << "�ԱݿϷ�" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "����� ���� ���� �Դϴ�" << std::endl;
}
void AccountHandler::WithdrawMoney(void)
{
	int id;
	int money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "��ݾ�: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Widthdraw(money) == 0)
			{
				std::cout << "�ܾ׺���" << std::endl << std::endl;
				return;
			}
			std::cout << "��ݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "����� ���� ���� �Դϴ�." << std::endl;
}
void AccountHandler::ShowAllAccinfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}



Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) :accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}


int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Widthdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	std::cout << "����ID: " << accID << std::endl;
	std::cout << "�� ��: " << cusName << std::endl;
	std::cout << "�� ��: " << balance << std::endl << std::endl;
}

Account::~Account()
{
	delete[]cusName;
}