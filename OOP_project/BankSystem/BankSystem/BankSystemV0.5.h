
#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* 2022.03.09 (�ݿ���¥)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4 -> 0.6
* Developer : Hyeonjun
* Context: �⺻Ʋ C++���� Ŭ����ȭ + ���� ������ ������ �� const �߰�
* ���¹�ȣ �ߺ��˻�� �Ա� �� ��ݾ� 0���� ũ�ٶ�� �Է����� ����
*/


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

//���α׷� ����� ���� ���� �޴� ���� 
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//�ſ��� 
enum { LEVEL_A = 7,LEVEL_B = 4,LEVEL_C = 2 };

//������ ����
enum {NORMAL = 1, CREDIT = 2};

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
	virtual void Deposit(int money);
	int Widthdraw(int money);
	void ShowAccInfo() const;
	~Account();
};


class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int ID,int money,char* name,int rate) : Account(ID,money,name), interRate(rate)
	{ }
	virtual void Deposit(int money);
};

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID,int money,char* name,int rate,int special) : NormalAccount(ID,money,name,rate), specialRate(special)
	{ }
	virtual void Deposit(int money);
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
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};





