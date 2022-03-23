

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accNum(0)
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
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입  금" << std::endl;
	std::cout << "3. 출  금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	std::cout << "[계좌종류선택]" << std::endl;
	std::cout << "1.보통예금계좌 ";
	std::cout << "2.신용신뢰 계좌 " << std::endl;
	std::cout << "선택: ";
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

	std::cout << "[보통예금계좌]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "이름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> balance;
	std::cout << "이자율: "; std::cin >> interRate;
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

	std::cout << "[신용신뢰계좌개설]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "이름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> balance;
	std::cout << "이자율: "; std::cin >> interRate;
	std::cout << "신용등급(1toA, 2toB, 3toC): "; std::cin >> creditLevel;
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
	std::cout << "[입  금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			std::cout << "입금완료" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "전산상에 없는 계좌 입니다" << std::endl;
}
void AccountHandler::WithdrawMoney(void)
{
	int id;
	int money;
	std::cout << "[출  금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "출금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Widthdraw(money) == 0)
			{
				std::cout << "잔액부족" << std::endl << std::endl;
				return;
			}
			std::cout << "출금완료" << std::endl;
			return;
		}
	}
	std::cout << "전산상에 없는 계좌 입니다." << std::endl;
}
void AccountHandler::ShowAllAccinfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}