// ClassTemplatePartialSpecialization.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template <typename T1 , typename T2>
class MySimple
{
public:
    void WhoAreyou()
    {
        std::cout << "size of T1: " << sizeof(T1) << std::endl;
        std::cout << "size of T2: " << sizeof(T2) << std::endl;
        std::cout << " <typename T1 , typenmae T2 > " << std::endl;
    }
};

template <>
class MySimple<int, double>
{
public:
    void WhoAreYou()
    {
        std::cout << "size of int:" << sizeof(int) << std::endl;
        std::cout << "size of double:" << sizeof(double) << std::endl;
        std::cout << "<int,double>" << std::endl;
    }
};


template <typename T1>
class MySimple<T1, double>
{
public:
    void WhoAreYou()
    {
        std::cout << "size of T1: " << sizeof(T1) << std::endl;
        std::cout << "size of double: " << sizeof(double) << std::endl;
        std::cout << "<T1,double>" << std::endl;
    }
};


int main()
{
    MySimple<char, double> obj1;
    obj1.WhoAreYou();
    MySimple<int, long> obj2;
    obj2.WhoAreyou();
    MySimple<int, double> obj3;
    obj3.WhoAreYou();
   
    return 0;
}

