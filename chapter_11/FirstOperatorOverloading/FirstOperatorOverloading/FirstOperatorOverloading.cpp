// FirstOperatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class First 
{
private:
	int num1, num2;
public:
	First(int n1 = 0,int n2 = 0):num1(n1),num2(n2)
	{ }
	void ShowData() 
	{
		std::cout << num1 << ", " << num2 << std::endl;
	}
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0):num3(n3),num4(n4)
	{ }
	void ShowData()
	{
		std::cout << num3 << ", " << num4 << std::endl;
	}
	Second& operator=(const Second& ref)
	{
		std::cout << "Second Operator=()" << std::endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};


int main()
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;
	scpy = ssrc;
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return EXIT_SUCCESS;
}

