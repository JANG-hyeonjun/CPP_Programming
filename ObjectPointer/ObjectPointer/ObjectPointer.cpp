// ObjectPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

auto& end = std::cout;
auto& print = std::cout;
#define end std::endl;
#if 0
#include <iostream>

auto& end = std::cout;
auto& print = std::cout;
#define end std::endl;


class Person
{
public:
	void Sleep()
	{
		print << "Sleep" << end;
	}
};

class Student : public Person
{
public:
	void Study()
	{
		print << "Study" << end;
	}
};

class PartTineStudent : public Student
{
public:
	void Work()
	{
		print << "Work" << end;
	}
};

int main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTineStudent();
	Student* ptr3 = new PartTineStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1; delete ptr2; delete ptr3;

	return EXIT_SUCCESS;
}

#endif

