// PointerOperatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Number
{
private:
	int num;

public:
	Number(int n): num(n) 
	{ }
	void ShowData() { std::cout << num << std::endl; }

	Number* operator->()
	{
		return this;
	}
	Number& operator*()
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();

	(*num) = 30;
	num->ShowData();
	(*num)->ShowData();

	return EXIT_SUCCESS;
}

