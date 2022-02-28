// ATMSim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;

};

class DepositException : public AccountException
{
private:
	int reqDep; //입금 금액

public:
	DepositException(int moeny) : reqDep(moeny)
	{ }
	void ShowExceptionReason()
	{
		std::cout << "[예외 메세지: " << reqDep << "는 입금 불가]" << std::endl;
	}
};

class WithdrawException : public AccountException
{
private:
	int balance;
public:
	WithdrawException(int money) :balance(money)
	{ }
	void ShowExceptionReason()
	{
		std::cout << "[예외 메세지: " << balance << "는 출금 불가]" << std::endl;
	}
};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(char* acc, int money) :balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (AccountException)
	{
		if (money > balance)
		{
			throw WithdrawException(balance);
		}
		balance -= money;
	}
	void ShowMyMoney()
	{
		std::cout << "잔고: " << balance << std::endl << std::endl;
	}
};


int main()
{
	Account myAcc((char*)"56789-82710", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	return 0;
}

