#include <iostream>
#if 0
class BaseOne
{
public:
	void SimpleFunc()
	{
		std::cout << "BaseOne" << std::endl;
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		std::cout << "Basetwo" << std::endl;
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void complexFunc()
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};
int main()
{
	//접근 제한자를 protected로 지정하게 되면 public처럼 접근이 가능하지만 
	//객체에서는 직접 접근이 불가능하다.
	MultiDerived mdr;
	mdr.complexFunc();

	return 0;
}

#endif