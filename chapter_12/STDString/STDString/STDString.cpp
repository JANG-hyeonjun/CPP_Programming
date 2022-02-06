// STDString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>


int main()
{
	std::string str1 = "I like";
	std::string str2 = "string class";
	std::string str3 = str1 + str2;
	//이 문장을 통해 +operator overloading이 되었다는것을 알 수 있다. 

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	//<<또한 overloding 되었다는 것을 알 수 있다. 

	str1 += str2;

	if (str1 == str3)
	{
		std::cout << "동일 문자열!" << std::endl;
	}
	else
	{
		std::cout << "동일 하지 않은 문자열!" << std::endl;
	}

	std::string str4;
	std::cout << "문자열 입력: ";
	std::cin >> str4;
	std::cout << "입력한 문자열: " << str4 << std::endl;
	return 0;
}

