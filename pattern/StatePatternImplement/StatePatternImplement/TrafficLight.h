#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "TrafficLightState.h"
#include "TrafficLightMemento.h"

class TrafficLight
{
public:
	explicit TrafficLight();
	void setState(State* pState);
	void Speak();
	void Wait();

	int					 GetListsize() { return MementoList.size(); }
	TrafficLightMemento* GetListElement(int idx) { return MementoList[idx]; }

	void CreateMemento();
	
private:
	State* mState = nullptr;
	TrafficLightMemento* mMemento = nullptr;
	std::vector<TrafficLightMemento*> MementoList;
};

