#pragma once

#define _CRT_SECURE_NO_WARNINGS

/*
* Banking Sysyem Ver 0.1
* Developer : Hyeonjun
* Context: �⺻Ʋ C����
* ���¹�ȣ �ߺ��˻�� �Ա� �� ��ݾ� 0���� ũ�ٶ�� �Է����� ���� 
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





