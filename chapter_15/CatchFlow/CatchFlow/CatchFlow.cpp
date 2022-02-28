// CatchFlow.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class AAA
{
public:
    void Showyou()
    {
        std::cout << "AAA exception!" << std::endl;
    }
};

class BBB :public AAA
{
public:
    void Showyou()
    {
        std::cout << "BBB exception!" << std::endl;
    }
};

class CCC : public BBB
{
public:
    void Showyou()
    {
        std::cout << "CCC exception!" << std::endl;
    }
};

void ExceptionGnerator(int expn)
{
    if (expn == 1)
    {
        throw AAA();
    }
    else if (expn == 2)
    {
        throw BBB();
    }
    else
    {
        throw CCC();
    }
}

int main()
{
    try
    {
        //ExceptionGnerator(3);
        ExceptionGnerator(2);
        //ExceptionGnerator(1);
    }
    catch (CCC& expn)
    {
        std::cout << "catch(CCC& expn)" << std::endl;
        expn.Showyou();
    }
    catch (BBB& expn)
    {
        std::cout << "catch(BBB& expn)" << std::endl;
        expn.Showyou();
    }
    catch(AAA& expn)
    {
        std::cout << "catch(AAA& expn)" << std::endl;
        expn.Showyou();
    }
    return 0;
}

