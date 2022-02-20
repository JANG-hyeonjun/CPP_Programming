#include <iostream>
#include "PointTemplate.h"

template <typename T>
Point<T>::Point(T x, T y): xpos(x),ypos(y)
{ }

template<typename T>
void Point<T>::ShowPostion() const
{
	std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
}

