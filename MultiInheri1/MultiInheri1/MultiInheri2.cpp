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
	//���� �����ڸ� protected�� �����ϰ� �Ǹ� publicó�� ������ ���������� 
	//��ü������ ���� ������ �Ұ����ϴ�.
	MultiDerived mdr;
	mdr.complexFunc();

	return 0;
}

#endif