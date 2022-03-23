#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include "BankingCommonDecl.h"


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
	std::cout << "°èÁÂID: " << accID << std::endl;
	std::cout << "ÀÌ ¸§: " << cusName << std::endl;
	std::cout << "ÀÜ ¾×: " << balance << std::endl << std::endl;
}

Account::~Account()
{
	delete[]cusName;
}