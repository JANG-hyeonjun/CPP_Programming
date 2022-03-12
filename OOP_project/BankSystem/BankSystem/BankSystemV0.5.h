
#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* 2022.03.09 (반영날짜)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4 -> 0.6
* Developer : Hyeonjun
* Context: 기본틀 C++구현 클래스화 + 복사 생성자 생성자 및 const 추가
* 계좌번호 중복검사와 입금 및 출금액 0보다 크다라는 입력으로 가정
*/


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

//프로그램 사용을 위한 선택 메뉴 구성 
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급 
enum { LEVEL_A = 7,LEVEL_B = 4,LEVEL_C = 2 };

//계좌의 종류
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





