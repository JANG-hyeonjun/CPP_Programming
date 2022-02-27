// ClassTemplateStaticMem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template <typename T>
class SimpleStaticMem
{
private:
	static T mem;
public:
	void Addmem(int num) 
	{
		mem += num;
	}
	void ShowMem()
	{
		std::cout << mem << std::endl;
	}
};

template <typename T>
T SimpleStaticMem<T>::mem = 0;

template <>
long SimpleStaticMem<long>::mem = 5;

int main()
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;

	obj1.Addmem(2);
	obj1.Addmem(3);
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;

	obj3.Addmem(100);
	obj4.ShowMem();

	return 0;
}

