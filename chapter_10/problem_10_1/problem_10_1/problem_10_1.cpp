// problem_10_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0,int y = 0): xpos(x),ypos(y)
	{ }

	void ShowPosition()
	{
		std::cout << '['<< xpos << " , " << ypos <<']' << std::endl;
	}
	

	Point& operator+=(const Point& pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}
	Point& operator-=(const Point& pos)
	{
		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}

	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);

};


bool operator ==(const Point& pos1, const Point& pos2)
{
	return pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos;
}


bool operator !=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}


Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}


int main()
{
	
	Point pos1(2, 4);
	Point pos2(1, 4);

	/*Point pos3 = pos1 - pos2;
	pos3.ShowPosition();

	pos3 += pos1;

	pos3.ShowPosition();


	pos3 -= pos1;

	pos3.ShowPosition();*/

	if (pos1 == pos2)
	{
		std::cout << "true" <<  std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	return 0;
}

