
#include <iostream>
#include "PointTemplate.h"
#include "PointTemplate.cpp"

int main(void)
{

	Point<int> pos1(3, 4);
	pos1.ShowPostion();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPostion();


	Point<char> pos3('P', 'F');
	pos3.ShowPostion();

	return 0;
}