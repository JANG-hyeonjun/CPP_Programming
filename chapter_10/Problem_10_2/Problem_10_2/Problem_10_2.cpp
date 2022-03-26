// Problem_10_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
	
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	Point& operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point& operator--(Point& ref);
	friend Point& operator~(Point& ref);
};



Point& operator~(Point& ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}


Point& operator--(Point& ref)
{
	ref.xpos = 1;
	ref.ypos -= 1;
	return ref;
}



int main()
{
	
	Point pos(1, 3);
	Point pos1 = -pos;
	pos1.ShowPosition();

	pos = ~pos1;

	pos.ShowPosition();


	
	return 0;
}

