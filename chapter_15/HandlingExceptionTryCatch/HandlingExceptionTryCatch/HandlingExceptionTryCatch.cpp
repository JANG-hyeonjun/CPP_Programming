// HandlingExceptionTryCatch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "두개의 숫자 입력: ";
    std::cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
		{
			throw num2;
		}
		std::cout << "나눗셈 몫: " << num1 / num2 << std::endl;
		std::cout << "나눗셈 나머지: " << num1 % num2 << std::endl;
	}
	catch (int expn)
	{
		std::cout << "제수는 " << expn << "이 될수 없습니다." << std::endl;
		std::cout << "프로그램을 다시 실행하세요." << std::endl;
	}
	std::cout << "end of main" << std::endl;
    return 0;
}

