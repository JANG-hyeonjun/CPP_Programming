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
	int sel;
	std::cout << "[������������]" << std::endl;
	std::cout << "1.���뿹�ݰ��� ";
	std::cout << "2.�ſ�ŷ� ���� " << std::endl;
	std::cout << "����: ";
	std::cin >> sel;

	if (sel == NORMAL)
	{
		MakeNormalAccount();
	}
	else
	{
		MakeCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	std::cout << "[���뿹�ݰ���]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�̸�: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;
	std::cout << "������: "; std::cin >> interRate;
	std::cout << std::endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	std::cout << "[�ſ�ŷڰ��°���]" << std::endl;
	std::cout << "����ID: "; std::cin >> id;
	std::cout << "�̸�: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> balance;
	std::cout << "������: "; std::cin >> interRate; 
	std::cout << "�ſ���(1toA, 2toB, 3toC): "; std::cin >> creditLevel;
	std::cout << std::endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
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


void NormalAccount::Deposit(int money) 
{
	Account::Deposit(money);
	Account::Deposit((money * interRate / 100));
}


void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money);
	Account:; Deposit(money * (specialRate / 100));
}