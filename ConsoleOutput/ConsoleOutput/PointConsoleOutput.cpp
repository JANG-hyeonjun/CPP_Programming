#include <iostream>
//istream�� ostream�� �ڽ��̴�. �� Ŭ������ ��� ����(���� ���)
//����°� ���õ� ��� �����Ϳ� ����� ��� �ִ�.

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition()
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, Point&);
	//�̸��� ����Ʈ ���̺귯������ ������ �����ε��� �Ҽ� �ִٴ� �ǹ��̴�. 
	//�̴� ������ �߿� �ֳĸ� ���� � �ڷ����� ���ϴ´�� ����ϰ� ������ 
	//�̷��� ������ �����ε��� �ϰ� �Ǹ� ������ ȿ����
};

std::istream& operator >>(std::istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos<< ']' << std::endl;
	return os;
}


int main(void)
{
	
	Point pos1;
	std::cout << "x ,y ��ǥ ������ �Է�: ";
	std::cin >> pos1;
	std::cout << pos1;
	
	Point pos2;
	std::cout << "x ,y ��ǥ ������ �Է�: ";
	std::cin >> pos2;
	std::cout << pos2;

	
	return EXIT_SUCCESS;
}

//int main(void)
//{
//	Point pos1(1, 3);
//	std::cout << pos1;
//	Point pos2(101, 103);
//	std::cout << pos2;
//
//	return EXIT_SUCCESS;
//}
