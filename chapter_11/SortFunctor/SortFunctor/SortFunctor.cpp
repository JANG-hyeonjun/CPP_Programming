// SortFunctor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
		{ 
			return true;
		}
		else
		{
			return false;
		}
	}
};

class DescendingSort : public SortRule
{
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class DataStorage //int 형 정수 저장소 
{
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			std::cout << "더이상 저장이 불가능 합니다." << std::endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}
	void SortData(const SortRule& functor)
	{
		for (int i = 0; i < (idx - 1); i++)
		{
			for (int j = 0; j < (idx - 1) - i; j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main()
{
	DataStorage storage(5);

	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);
	
	storage.SortData(AscendingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	return 0;
}

