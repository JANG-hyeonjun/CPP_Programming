// MultiInherit3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Base
{
public:
	Base()
	{
		std::cout << "Base Constructor" << std::endl;
	}

	void SimpleFunc()
	{
		std::cout << "Base One" << std::endl;
	}
};


class MiddleDerivedOne : public Base
{
public:
	MiddleDerivedOne() : Base()
	{
		std::cout << "Middle DerivedOne Contructor" << std::endl;
	}

	void MiddleFuncOne()
	{
		SimpleFunc();
		std::cout << "Middle DerivedOne" << std::endl;
	}

};

class MiddleDerivedTwo : public Base
{
public:
	MiddleDerivedTwo() : Base()
	{
		std::cout << "Middle DerivedTwo Contructor" << std::endl;
	}

	void MiddleFuncTwo()
	{
		SimpleFunc();
		std::cout << "Middle DerivedTwo" << std::endl;
	}
};


class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		std::cout << "LastDerived Constructor" << std::endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		MiddleDerivedOne::SimpleFunc();
	}
};


int main()
{
	
	std::cout << "객체 생성 전.........." << std::endl;
	LastDerived ldr;
	std::cout << "객체 생성 후.........." << std::endl;
	ldr.ComplexFunc();


	return 0;
}

