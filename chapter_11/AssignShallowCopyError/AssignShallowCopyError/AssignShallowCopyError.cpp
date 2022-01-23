// AssignShallowCopyError.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Person
{
private:
	char* name;
	int age;

public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		std::cout << "이름: " << name << std::endl;
		std::cout << "나이: " << age << std::endl;
	}

	Person& operator=(const Person& ref)
	{
		delete[] name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name,ref.name);
		age = ref.age;
		return *this;
	}
	~Person()
	{
		delete[] name;
		std::cout << "Called destructor" << std::endl;
	}
};

int main()
{
	Person man1((char*)"Lee dong woo", 29);
	Person man2((char*)"Yoon ji yul", 22);

	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return EXIT_SUCCESS;
}

