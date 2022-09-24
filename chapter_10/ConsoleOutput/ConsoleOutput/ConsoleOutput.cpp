// ConsoleOutput.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

namespace Mystd
{
	class ostream
	{
	public:
		ostream& operator<<(const char* str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(const char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<<(const int num)
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<<(const double e)
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator<<(ostream& (*fp)(ostream& ostm))
		{
			return fp(*this);
		}
	};

	static ostream& endl(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main()
{
	Mystd::cout << "simple String";
	Mystd::cout << Mystd::endl;
	Mystd::cout << 3.14;
	Mystd::cout << Mystd::endl;
	std::endl(std::cout);

	return EXIT_SUCCESS;
}