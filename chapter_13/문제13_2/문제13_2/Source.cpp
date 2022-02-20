#include <iostream>



template <typename T> 


T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr1[] = { 10,20,30 };
	std::cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << std::endl;
	double arr2[] = { 10.3,20.4,30.5 };
	std::cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << std::endl;

	return 0;
}