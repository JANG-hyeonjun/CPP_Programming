#pragma once

#include <iostream>
#include <cstdlib>

template <typename T> 
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {} //복사 생성자
	BoundCheckArray& operator=(const BoundCheckArray& arr) { } //연산자 오버로딩 대입연산자 

public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};


template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len):arrlen(len)
{ 
	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	//std::cout << "T&" << std::endl;
	if (idx < 0 || idx >= arrlen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}
	return arr[idx];
}


template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	std::cout << "T" << std::endl;
	if (idx < 0 || idx >= arrlen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}