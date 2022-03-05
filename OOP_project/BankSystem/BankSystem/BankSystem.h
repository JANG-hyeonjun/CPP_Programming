#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* Banking Sysyem Ver 0.1
* Developer : Hyeonjun
* Context: 기본틀 C구현
* 계좌번호 중복검사와 입금 및 출금액 0보다 크다라는 입력으로 가정 
*/


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccinfo(void);

enum { MAKE = 1,DEPOSIT,WITHDRAW,INQUIRE,EXIT };

typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LEN];

}Account;

Account accArr[100];
int accNum = 0;





