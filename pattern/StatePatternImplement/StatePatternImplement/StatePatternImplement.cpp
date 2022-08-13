// StatePatternImplement.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include "TrafficLight.h"

int main()
{
	auto trafficLight = new TrafficLight();
	
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();
	trafficLight->Wait();
	trafficLight->Speak();

	return EXIT_SUCCESS;
}

