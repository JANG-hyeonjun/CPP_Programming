#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
	mState = new GreenLight("GreenLight");
	CreateMemento();
}

void TrafficLight::setState(State* pState)
{
	mState = pState;
}

void TrafficLight::Speak()
{
	mState->Speak();
}

void TrafficLight::Wait()
{
	mState->Wait(this);
}

void TrafficLight::CreateMemento()
{
	mMemento = new TrafficLightMemento(mState->GetString());
	MementoList.emplace_back(mMemento);
}
