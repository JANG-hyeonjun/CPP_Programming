// AdapterPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Animal abstract
{
public:
	virtual void walk() abstract;
};

class Cat : public Animal
{
public:
	virtual void walk() override
	{
		std::cout << "cat Walking" << std::endl;
	}
};

class Dog : public Animal
{
public:
	virtual void walk() override
	{
		std::cout << "dog walking" << std::endl;
	}
};

class Fish
{
public:
	void swim()
	{
		std::cout << "Fish Swimming" << std::endl;
	}
};

class FishAdapter
{
public:
	FishAdapter(Fish* fish)
	{
		this->fish = fish;
	}
	~FishAdapter()
	{
		if(fish)
			delete fish;
	}
	void walk()
	{
		if (fish)
			fish->swim();
	}
private:
	Fish* fish = nullptr;
};

void makeWalk(Animal* animal)
{
	animal->walk();
}

int main()
{
	Cat* kitty = new Cat();
	kitty->walk();
	Dog* bingo = new Dog();
	bingo->walk();
	Fish* nemo = new Fish();
	
	FishAdapter* adaptedNemo = new FishAdapter(nemo);
	adaptedNemo->walk();

	delete adaptedNemo;
	delete kitty;
	delete bingo;

	return EXIT_SUCCESS;
}

