// VirtualDestructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class First
{
private:
    char* strOne;
public:
    First(char* str)
    {
        strOne = new char[strlen(str) + 1];
    }
   virtual ~First()
    {
        std::cout << "~First()" << std::endl;
        delete[]strOne;
    }
};

class Second : public First
{
private:
    char* strTwo;
public:
    Second(char* str1, char* str2) : First(str1)
    {
        strTwo = new char[strlen(str2) + 1];
    }
    virtual ~Second()
    {
        std::cout << "~Second()" << std::endl;
        delete[] strTwo;
    }
};
//
//int main()
//{
//    First* ptr = new Second((char*)"Simple", (char*)"complex");
//    delete ptr;
//    return 0;
//}

