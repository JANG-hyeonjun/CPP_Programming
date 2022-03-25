// PowerfullCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{ }
	void ShowCarState()
	{
		std::cout << "잔여 연료량: " << fuelGauge << std::endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
	{ }
	void ShowTruckState()
	{
		ShowCarState();
		std::cout << "화물의 무게: " << freightWeight << std::endl;
	}
};

int main()
{

	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();
	std::cout << std::endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);
	ptruck2->ShowTruckState();
	std::cout << std::endl;

	Truck* ptruck3 = new Truck(90, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);

	pcar3->ShowCarState();
	
	return 0;
}

