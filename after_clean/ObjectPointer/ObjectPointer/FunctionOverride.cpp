#include <iostream>

class First
{
public:
	virtual void MyFunc()
	{
		std::cout << "FirstFunc" << std::endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()
	{
		std::cout << "SecondFunc" << std::endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		std::cout << "ThirdFunc" << std::endl;
	}
};
#if 0
int main()
{

	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	delete tptr;
	
	return 0;
}

#endif