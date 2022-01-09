#include <iostream>

#if 0
class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition()
	{
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}

	Point& operator++() // 전위 증가 연산자 
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point operator++(int) //후위 증가 연산자
	{
		const Point retobj(xpos, ypos); // const Point retobj(*this) -> 디폴트 복사 생성자 사용
		xpos += 1;
		ypos += 1;
		return retobj;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref) //전위 감소 연산자
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
const Point operator--(Point& ref, int) //후위 감소 연산자
{
	//const Point retobj(ref.xpos,ref.ypos);
	const Point retobj(ref);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}


int main(void)
{
	Point pos(3, 5);
	Point cpy;

	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;
	cpy.ShowPosition();
	pos.ShowPosition();

	return EXIT_SUCCESS;
}
#endif