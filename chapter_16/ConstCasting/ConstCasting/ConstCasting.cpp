// ConstCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


void ShowString(char* str)
{
	std::cout << str << std::endl;
}

void ShowAddResult(int& n1, int& n2)
{
	std::cout << n1 + n2 << std::endl;
}

int main()
{
	const char* name = "Lee sung ju";
	ShowString(const_cast<char*>(name));

	const int& num1 = 100;
	const int& num2 = 200;

	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));

	return 0;
}

