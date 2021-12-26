#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Employee
{
private:
	char name[100];

public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		std::cout << "name: " << name << std::endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;

public:
	TemporaryWorker(char * name,int pay) : Employee(name),workTime(0),payPerHour(pay)
	{}

	void AddWorkTime(int time)
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class PermenanentWorker : public Employee
{
private:
	int salary;
public:
	PermenanentWorker(char * name,int money)
		: Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryIfno() const
	{
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class SaleWorker : public PermenanentWorker
{
private:
	int salesResult; //월 판매실적 
	double bonusRatio; //상여금 비율 

public:
	SaleWorker(char * name,int money,double ratio) : 
		PermenanentWorker(name,money), salesResult(0) , bonusRatio(ratio)
	{}

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const
	{
		return PermenanentWorker::GetPay(); +(int)(salesResult * bonusRatio);
	}
	void ShowsalaryInfo() const
	{
		ShowYourName();
		std::cout << "salary: " << GetPay() << std::endl << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		std::cout << "salary sum: " << sum <<std::endl;
	}
	~EmployeeHandler()
	{
		for (int i =0; i < empNum; ++i)
		{
			delete empList[i];
		}
	}
};

int main()
{
	EmployeeHandler handler;


	//정규직 등록
	handler.AddEmployee(new PermenanentWorker((char*)"Kim", 1000));
	handler.AddEmployee(new PermenanentWorker((char*)"Lee", 1500));
	
	//임시직 등록
	TemporaryWorker* alba = new TemporaryWorker((char*)"Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직 등록
	SaleWorker* seller = new SaleWorker((char*)"Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();

	
	return 0;
}