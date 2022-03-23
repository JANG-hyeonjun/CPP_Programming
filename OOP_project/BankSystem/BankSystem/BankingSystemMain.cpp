#include "BankingCommonDecl.h"
#include "AccountHandler.h"


/*
* 2022.03.23 (반영날짜)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4 -> 0.6 -> 0.7
* Developer : Hyeonjun
* Context: 기본틀 C++구현 클래스화 + 복사 생성자 생성자 및 const 추가
* 계좌번호 중복검사와 입금 및 출금액 0보다 크다라는 입력으로 가정
* 헤더 파일과 소스 파일 분리 
*/

int main(void)
{
	int choice = 0;
	AccountHandler* manager = new AccountHandler;

	while (1)
	{
		manager->ShowMenu();
		std::cout << "선택: ";
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