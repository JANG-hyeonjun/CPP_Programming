// OneOpndOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class Point
{
private:
	int xpos, ypos;

public:
	Point(int x=0,int y=0) : xpos(x),ypos(y)
	{ }
	void showPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	//문제 1
	Point operator-()
	{
		Point temp_pos = *this;
		temp_pos.xpos *= -1;
		temp_pos.ypos *= -1;

		return temp_pos;

		//더 좋은 코드는 없을까? -> refactoring 
		/*
		Point temp = (-xpos, -ypos);
		return temp;
		*/
	}
	friend Point& operator--(Point& ref);
	friend Point operator~(const Point& ref);
};

//문제2
Point operator~(const Point& ref)
{
	const Point temp(ref.ypos, ref.xpos);
	return temp;
}

Point& operator--(Point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main()
{
	Point pos(1, 2);
	++pos;
	pos.showPosition();
	--pos;
	pos.showPosition();
	++(++pos);
	pos.showPosition();
	--(--pos);
	pos.showPosition();

	Point pos1(10, 20);
	pos1.showPosition();

	Point pos2 = -pos1;

	pos2.showPosition();
	pos1.showPosition();


	Point pos3 = ~pos1;
	pos3.showPosition();
	pos1.showPosition();

	pos2.showPosition();
	(~pos2).showPosition();

	return EXIT_SUCCESS;
}

