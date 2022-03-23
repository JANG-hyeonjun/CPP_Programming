#include "BankingCommonDecl.h"
#include "AccountHandler.h"


/*
* 2022.03.23 (�ݿ���¥)
* Banking Sysyem Ver 0.2 -> 0.3 -> 0.4 -> 0.6 -> 0.7
* Developer : Hyeonjun
* Context: �⺻Ʋ C++���� Ŭ����ȭ + ���� ������ ������ �� const �߰�
* ���¹�ȣ �ߺ��˻�� �Ա� �� ��ݾ� 0���� ũ�ٶ�� �Է����� ����
* ��� ���ϰ� �ҽ� ���� �и� 
*/

int main(void)
{
	int choice = 0;
	AccountHandler* manager = new AccountHandler;

	while (1)
	{
		manager->ShowMenu();
		std::cout << "����: ";
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