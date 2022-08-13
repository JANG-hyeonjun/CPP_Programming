#pragma once

#include <iostream>
#include <string>
#include <vector>

class TrafficLightMemento
{
public:
	explicit TrafficLightMemento(std::string str);
	
	std::string GetString() { return mStateStringForMemento; }

private:
	std::string mStateStringForMemento;
};
