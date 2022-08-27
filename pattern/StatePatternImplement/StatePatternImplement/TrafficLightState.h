#pragma once
#include <iostream>
#include <string>
#include <vector>

class TrafficLight;
class TrafficLightMemento;

class State
{
public:
	explicit State(std::string str);
	virtual void Speak() abstract;
	virtual void Wait(TrafficLight* pTrafficLight) abstract;

	std::string  GetString() { return mStateName; }
	void		 SetString(std::string pStr) { mStateName = pStr; }

private:
	std::string mStateName;
};

class GreenLight : public State
{
public:
	explicit GreenLight(std::string str); 
	virtual void Speak() override;
	virtual void Wait(TrafficLight* pTrafficLight) override;
};

class YellowLight : public State
{
public:
	explicit YellowLight(std::string str);
	virtual void Speak() override;
	virtual void Wait(TrafficLight* pTrafficLight);
};

class RedLight : public State
{
public:
	explicit RedLight(std::string str);
	virtual void Speak() override;
	virtual void Wait(TrafficLight* pTrafficLight);
};

