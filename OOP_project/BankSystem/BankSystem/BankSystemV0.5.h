
#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* 2022.03.09 (반영날짜)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4
* Developer : Hyeonjun
* Context: 기본틀 C++구현 클래스화 + 복사 생성자 생성자 및 const 추가
* 계좌번호 중복검사와 입금 및 출금액 0보다 크다라는 입력으로 가정
*/


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//추후 이러한 함수를 가지고있는 Manager Class를 두면 좋을 듯 


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





