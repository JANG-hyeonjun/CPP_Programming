#include <iostream>

template <class T1,class T2>
void ShowData(double num)
{
	std::cout << (T1)num << ", " << (T2)num << std::endl;
}

int main()
{
	ShowData<char,int>(65);
	ShowData<char,int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(68.9);
	ShowData<short, double>(68.9);

	return EXIT_SUCCESS;
}