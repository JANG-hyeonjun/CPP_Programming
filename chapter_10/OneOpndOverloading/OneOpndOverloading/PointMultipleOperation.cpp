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
	return ref * times; //���� ����Լ��� ������ �����ε��� �̿�
	//���� ������ �Ʒ� ����� ����.
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