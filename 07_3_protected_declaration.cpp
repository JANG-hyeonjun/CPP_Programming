// 07_3_protected_declaration.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#if 0
class Base
{
	private:
		int num1;
	protected:
		int num2;
	public:
		int num3;

	Base() : num1(1), num2(2) , num3(3)
	{}
};

class Derived : protected Base {};


int main()
{
	
	Derived drv;
	std::cout << drv.num3  << std::endl;



	return EXIT_SUCCESS;
}

#endif 

