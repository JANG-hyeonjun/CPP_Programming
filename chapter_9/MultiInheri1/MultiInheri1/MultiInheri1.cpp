// MultiInheri1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#if 0
#include <iostream>

class BaseOne
{
public:
	void SimpleFuncOne()
	{
		std::cout << "BaseOne" << std::endl;
	}
};

class BaseTwo
{
public:
	void SimpleFunTwo()
	{
		std::cout << "Basetwo" << std::endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void complexFunc()
	{
		SimpleFuncOne();
		SimpleFunTwo();
	}
};
int main()
{
	//접근 제한자를 protected로 지정하게 되면 public처럼 접근이 가능하지만 
	//객체에서는 직접 접근이 불가능하다.
	MultiDerived mdr;
	mdr.complexFunc();

	return 0;
}
#endif

