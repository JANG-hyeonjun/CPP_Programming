// InheritAssignOperation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0): num1(n1),num2(n2)
	{ }
	void ShowData()
	{
		std::cout << num1 << ", " << num2 << std::endl;
	}
	First& operator=(const First& ref)
	{
		std::cout << "First& operator=()" << std::endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1,int n2,int n3,int n4):First(n1,n2),num3(n3),num4(n4)
	{ }
	void ShowData()
	{
		First::ShowData();
		std::cout << num3 << ", " << num4 << std::endl;
	}
	
	Second& operator=(const Second& ref)
	{
		std::cout << "Second& operator=()" << std::endl;
		First::operator=(ref);
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
		/*
		이렇게 하면 유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면 
		기초클래스의 대입 연산자는 호출 되지 않아서 기초 클래스의 멤버 변수는 멤버 대 멤버 복사 (얇은 복사) 대상에서 제외 된다. 
		*/
	}
};

int main()
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);

	scpy = ssrc;
	scpy.ShowData();

	return EXIT_SUCCESS;
}

