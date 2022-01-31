// ConsoleOutput.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#if 0 

#include <iostream>

namespace mystd
{
    using namespace std;

    class ostream
    {
    public:
        ostream& operator<<(char* str)
        {
            printf("%s", str);
            return *this;
        }
        ostream& operator<<(char str)
        {
            printf("%c", str);
            return *this;
        }
        ostream& operator<<(int num)
        {
            printf("%d", num);
            return *this;
        }
        ostream& operator<<(double e)
        {
            printf("%g", e);
            return *this;
        }
        ostream& operator<< (ostream& (*fp)(ostream& ostm))
        {
            return fp(*this);
        }
    };
    
    ostream& endl(ostream& ostm)
    {
        ostm << '\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout;
}

int main()
{
   
    using mystd::cout;
    using mystd::endl;


   /*
   cout << (char*)"Simple String";
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    cout << endl;
    */

    cout << 3.14 << endl << 123 << endl;

    return EXIT_SUCCESS;
}

#endif
