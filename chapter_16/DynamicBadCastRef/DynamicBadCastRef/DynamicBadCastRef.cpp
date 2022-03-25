// DynamicBadCastRef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		std::cout << "SoSimeple Base Class" << std::endl;
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
	SoSimple simobj;
	SoSimple& ref = simobj;

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
		comRef.ShowSimpleInfo();
	}
	catch (std::bad_cast expt)
	{
		std::cout << expt.what() << std::endl;
	}
	
	return 0;
}

