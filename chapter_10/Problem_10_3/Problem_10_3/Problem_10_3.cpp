// Problem_10_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition()
	{
		std::cout << '[' << xpos << " , " << ypos << ']' << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
	friend std::istream& operator>>(std::istream& Is, Point& pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << " , " << pos.ypos << ']' << std::endl;
	return os;
}

std::istream& operator>>(std::istream& Is,Point& pos)
{
	Is >> pos.xpos >> pos.ypos;
	return Is;
}


int main()
{
	Point pos1;
	std::cin >> pos1;
	std::cout << pos1;
	
	return 0;
}


