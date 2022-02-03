// SmartPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Point
{
private: 
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x),ypos(y)
	{ 
		std::cout << "Point 객체 생성" << std::endl;
	}
	~Point()
	{
		std::cout << "Point 객체 소멸" << std::endl;
	}
	void Setpos(int x,int y)
	{
		xpos = x;
		ypos = y;
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

class SmartPtr
{
private:
	Point* posptr;
public:
	SmartPtr(Point* ptr) : posptr(ptr)
	{ }
	Point& operator*()
	{
		return *posptr;
	}
	Point* operator->()
	{
		return posptr;
	}
	~SmartPtr()
	{
		delete posptr;
	}
};

int main()
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(1, 2));
	
	std::cout << *sptr1;
	std::cout << *sptr2;
	std::cout << *sptr3;

	sptr1->Setpos(10, 20);
	sptr2->Setpos(30, 40);
	sptr3->Setpos(50, 60);

	std::cout << *sptr1;
	std::cout << *sptr2;
	std::cout << *sptr3;

	return EXIT_SUCCESS;
}

