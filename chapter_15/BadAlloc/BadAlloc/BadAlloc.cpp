// BadAlloc.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <new>



int main()
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			std::cout << num << "번째 할당 시도" << std::endl;
			new int[10000][10000];
		}
	}
	catch (std::bad_alloc& bad)
	{
		std::cout << bad.what() << std::endl;
		std::cout << "더이상 할당 불가" << std::endl;
	}
	return 0;
}

