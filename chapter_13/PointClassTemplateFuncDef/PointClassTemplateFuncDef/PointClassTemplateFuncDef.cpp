#include <iostream>

//진짜 복수 같은걸 하고 싶다면 그들보다 나은인간이 되어야한다,
//분노말고 실력으로 되갚아주자 나는 할 수 있다, 

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x,T y): xpos(x), ypos(y)
{ }

template <typename T> 
void Point<T>::ShowPosition() const
{
	std::cout << '[' << xpos << ", " <<  ypos <<']' << std::endl;
}

int main(void)
{
	Point <int> pos1(3, 4);
	pos1.ShowPosition();

	Point <double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point <char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}
