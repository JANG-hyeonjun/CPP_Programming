// Problem_11_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum):bullet(bnum)
	{ }
	void show_bullet_information()
	{
		std::cout << "남은 총알 개수: " << bullet << std::endl;
	}
	void shot()
	{
		std::cout << "BBANG!!!" << std::endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;

public:
	Police(int bnum,int bcuff): handcuffs(bcuff)
	{ 
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		std::cout << "SNAP!" << std::endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			std::cout << "Hut BBBANG!" << std::endl;
		else
			pistol->shot();
	}
	void Police_information() const
	{
		pistol->show_bullet_information();
		std::cout << "남은 수갑의 개수: " <<handcuffs << std::endl;
	}
	//복사 생성자
	Police(const Police& ref) :handcuffs(ref.handcuffs)
	{
		std::cout << "Called copy constructor" << std::endl;
		if (ref.pistol != NULL)
		{
			pistol = new Gun(*(ref.pistol)); //Gun의 디폴트 복사 생성자 호출 
		}
		else
		{
			pistol = NULL;
		}
	}
	//대입 연산자
	Police& operator=(const Police& ref)
	{
		std::cout << "Police& operator=()" << std::endl;
		
		//만약 이미 pistol이 있는데 바꾸면 메모리가 누수 될테니까 
		//계속 고민해 그냥 받아치지말고 어떠한 코드가 더 좋을지 계속 고민하자
		if (pistol != NULL)
			delete pistol;
		
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol)); //Gun의 디폴트 복사 생성자 호출 
		else
			pistol = NULL;
		//단순히 pistol = ref.pistol이란 문구로 해결하려고 하지말 것 메모리를 계속 생각해주어야한다.(물론 스마트 포인터가 있지만) 
		
		handcuffs = ref.handcuffs;
		return *this;
	}

	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};


int main()
{
	Police pman1(5, 3);
	pman1.Police_information();
	Police pman2(4, 3);
	pman2.Police_information();

	pman2 = pman1;

	pman2.Police_information();

	Police pman3 = pman1;
	pman3.Police_information();

	return EXIT_SUCCESS;
}

