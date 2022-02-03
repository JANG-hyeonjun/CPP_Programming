// ConvToObject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Number
{
private:
    int num;

public:
    Number(int n = 0) : num(n)
    {
        std::cout << "Number(int n = 0)" << std::endl;
    }
    Number& operator=(const Number& ref)
    {
        std::cout << "operator=()" << std::endl;
        num = ref.num;
        return *this;
    }
    void ShowNumber()
    {
        std::cout << num << std::endl;
    }
};

int main()
{
    Number num;
    num = 30; //num = Number(30)과정을 진행함 여기서 임시객체가 만들어진다.-> num.operator=(Number(30)) 이렇게 진행되어짐 
    num.ShowNumber();

    return 0;
}

