
#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* 2022.03.09 (�ݿ���¥)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4
* Developer : Hyeonjun
* Context: �⺻Ʋ C++���� Ŭ����ȭ + ���� ������ ������ �� const �߰�
* ���¹�ȣ �ߺ��˻�� �Ա� �� ��ݾ� 0���� ũ�ٶ�� �Է����� ����
*/


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//���� �̷��� �Լ��� �������ִ� Manager Class�� �θ� ���� �� 


class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);
	int GetAccID()const;
	void Deposit(int money);
	int Widthdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccinfo(void) const;
	~AccountHandler();
};





