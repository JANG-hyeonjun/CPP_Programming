#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


class computer
{
private:
	char owner[50];
public:
	computer(char* name)
	{
		strcpy(owner, name);
	}
	void Caculate()
	{
		std::cout << "요청 내용을 계산합니다." << std::endl;
	}
};
class Notebookcomp : public computer
{
private:
	int Battery;
public:
	Notebookcomp(char* name , int initChag) :computer(name), Battery(initChag)
	{}
	void Charging() 
	{ 
		Battery += 5;
	}
	void UseBattery() 
	{ 
		Battery -= 1; 
	}
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			std::cout << "충전이 필요합니다." << std::endl;
			return;
		}
		std::cout << "이동하면서 ";
		Caculate();
		UseBattery();
	}
	int GetBatteryInfo()
	{
		return Battery;
	}
};
class TableNotebook : public Notebookcomp
{
private:
	char regstPenModel[50];
public:
	TableNotebook(char* name, int initChag, char* pen) : Notebookcomp(name,initChag)
	{
		strcpy(regstPenModel, pen);
	}

	void Write(char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			std::cout << "충전이 필요합니다." << std::endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			std::cout << "등록된 펜이 아닙니다.";
			return;
		}
		std::cout << "필기 내용을 처리합니다." << std::endl;
		UseBattery();
	}
};

int main()
{
	Notebookcomp nc((char*)"이수종", 5);
	TableNotebook tn((char*)"정수영", 5, (char*)"ISE-241-242");
	nc.MovingCal();
	tn.Write((char*)"ISE-241-242");
	return 0;
}
