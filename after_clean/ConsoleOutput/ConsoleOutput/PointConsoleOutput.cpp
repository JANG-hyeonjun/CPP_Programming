#include <iostream>
//istream과 ostream의 자식이다. 두 클래스를 상속 받음(다중 상속)
//입출력과 관련된 모든 데이터와 기능을 담고 있다.

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
	//이말은 디폴트 라이브러리에서 연산자 오버로딩을 할수 있다는 의미이다. 
	//이는 굉장히 중요 왜냐면 내가 어떤 자료형을 원하는대로 출력하고 싶을때 
	//이렇게 연산자 오버로딩을 하게 되면 굉장히 효율적
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
	std::cout << "x ,y 좌표 순서로 입력: ";
	std::cin >> pos1;
	std::cout << pos1;
	
	Point pos2;
	std::cout << "x ,y 좌표 순서로 입력: ";
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
