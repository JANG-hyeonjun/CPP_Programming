// FunctionTemplateStaticVar.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	std::cout << num << " ";
}

int main()
{
	
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	std::cout << std::endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	std::cout << std::endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	std::cout << std::endl;

	return 0;
}

