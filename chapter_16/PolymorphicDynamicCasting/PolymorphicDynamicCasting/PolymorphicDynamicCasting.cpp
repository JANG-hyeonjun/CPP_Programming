// PolymorphicDynamicCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		std::cout << "SoSimple base class" << std::endl;
	}
};


class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		std::cout << "SoComplex Derived Class" << std::endl;
	}
};


int main()
{
	//SoSimple* simptr = new SoComplex;
	SoSimple* simptr = new SoSimple;
	SoComplex* comptr = dynamic_cast<SoComplex*>(simptr);
	if (comptr == NULL)
	{
		std::cout << "형 변환 실패" << std::endl;
	}
	else
	{
		comptr->ShowSimpleInfo();
	}
	return 0;
}

