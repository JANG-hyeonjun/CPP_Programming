#include "TrafficLightState.h"
#include "TrafficLight.h"

State::State(std::string str) : mStateName(str) { }

GreenLight::GreenLight(std::string str) :State(str) { }

void GreenLight::Speak()
{
	std::cout << "Now is GreenLight" << std::endl;
}

void GreenLight::Wait(TrafficLight* pTrafficLight)
{
	std::cout << "wait.. the light changed" << std::endl;
	pTrafficLight->CreateMemento();
	pTrafficLight->setState(new YellowLight("YellowLight"));
}

YellowLight::YellowLight(std::string str) : State(str) { }

void YellowLight::Speak()
{
	std::cout << "Now is YellowLight" << std::endl;
}

void YellowLight::Wait(TrafficLight* pTrafficLight)
{
	std::cout << "wait.. the light changed" << std::endl;

	int size = pTrafficLight->GetListsize();
	auto memento = pTrafficLight->GetListElement(size - 1);

	if (!memento->GetString().compare("RedLight"))
	{
		pTrafficLight->CreateMemento();
		pTrafficLight->setState(new GreenLight("GreenLight"));
	}
	else
	{
		pTrafficLight->CreateMemento();
		pTrafficLight->setState(new RedLight("RedLight"));
	}
}

RedLight::RedLight(std::string str) : State(str)
{
}

void RedLight::Speak()
{
	std::cout << "Now is RedLight" << std::endl;
}

void RedLight::Wait(TrafficLight* pTrafficLight)
{
	std::cout << "wait.. the light changed" << std::endl;
	pTrafficLight->CreateMemento();
	pTrafficLight->setState(new YellowLight("YellowLight"));
}
