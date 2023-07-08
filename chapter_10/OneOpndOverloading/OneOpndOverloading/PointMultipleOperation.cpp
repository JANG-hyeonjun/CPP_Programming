#include<iostream>

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
	
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	
	friend Point operator*(int times, Point& ref);

};

Point operator*(int times, Point& ref)
{
	return ref * times; //위에 멤버함수의 연산자 오버로딩을 이용
	//위의 문장은 아래 문장과 같다.
	/*
	Point pos(ref.xpos * times, ref.ypos * times);
	return pos;
	*/
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = 2* pos * 3;
	cpy.ShowPosition();
	
	return EXIT_SUCCESS;
}
#endif