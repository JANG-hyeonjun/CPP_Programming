// AddFunctionTemplate.cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template <typename T>

T Add(T num1, T num2)
{
	return num1 + num2; 
}


int main()
{
	std::cout << Add<int>(15, 20) << std::endl;
	std::cout << Add<double>(2.9, 3.7)<< std::endl;
	std::cout << Add<int>(3.2, 3.2) << std::endl;
	std::cout << Add<double>(3.14, 2.75) << std::endl;
	
	return EXIT_SUCCESS;
}

