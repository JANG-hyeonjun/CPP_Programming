﻿// ReThrow.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
		{
			throw 0;
		}
		std::cout << "목: " << num1 / num2 << std::endl;
		std::cout << "나머지: " << num1 % num2 << std::endl;
	}
	catch (int expn)
	{
		std::cout << "first catch" << std::endl;
		throw;
	}
}

int main()
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		std::cout << "second catch" << std::endl;
	}
	
	return 0;
}

