#include <iostream>



class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0):xpos(x),ypos(y)
	{ }
	void ShowPosition() const
	{ 
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template  <typename T>

void SwapData(T& pos1,T& pos2)
{
	T temp = pos1;
	pos1 = pos2;
	pos2 = temp;
}


int main()
{
	
	Point P1(5, 5);
	Point P2(3, 3);


	SwapData(P1, P2);

	P1.ShowPosition();
	P2.ShowPosition();

	return 0;
}
