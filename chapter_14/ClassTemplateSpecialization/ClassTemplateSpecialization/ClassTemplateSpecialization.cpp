// ClassTemplateSpecialization.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0 , T y = 0): xpos(x),ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos<< ']' << std::endl;
	}
};


template <typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data): mdata(data)
	{ }
	void ShowDataInfo(void)
	{
		std::cout << "Data: " << mdata << std::endl;
	}
};

template <>
class SimpleDataWrapper <char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}
	void ShowDataInfo(void)
	{
		std::cout << "String: " << mdata << std::endl;
		std::cout << "Length: " << strlen(mdata) << std::endl;
	}
	~SimpleDataWrapper()
	{
		delete[]mdata;
	}
};

template <>
class SimpleDataWrapper <Point<int>>
{
private:
	Point <int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{ }
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{
	SimpleDataWrapper<int> iwarp(170);
	iwarp.ShowDataInfo();
	SimpleDataWrapper<char*> swarp((char*)"Class Template Specialization");
	swarp.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswarp(3, 7);
	poswarp.ShowDataInfo();

	return 0;
}

