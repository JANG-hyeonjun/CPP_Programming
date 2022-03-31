// Modern_CPP_Shared_mutex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <shared_mutex>

struct MInt
{
	std::shared_mutex mtx;
	int num = 0;
	//std::vector , std::unordered_map
};

//class MInt
//{
//public:
//	void setNum(MInt& mi, int num)
//	{
//		mi.mtx.lock();
//		mi.num = num;
//		mi.mtx.unlock();
//	}
//
//	void printNum(MInt& mi)
//	{
//		mi.mtx.lock_shared();
//		std::cout << mi.num << std::endl;
//		mi.mtx.unlock_shared();
//	}
//private:
//	std::shared_mutex mtx;
//	int num = 0;
//	//std::vector , std::unordered_map
//};


void setNum(MInt& mi,int num)
{
	std::lock_guard<std::shared_mutex> lck(mi.mtx);
	mi.num = num;
}

void printNum(MInt& mi)
{
	std::shared_lock<std::shared_mutex> lck(mi.mtx);
	std::cout << mi.num << std::endl;

}

//그런데 여기서 RAII를 지원해주는 lock매니저 를 적용하는 편이 좋기 떄문에 위와 같이 적용해주는것이 좋다,
//RAII는 자원 획득을 초기화 해주는 패턴중 하나이다, 

int main()
{
	MInt mi;

	std::thread t0(printNum,std::ref(mi));
	std::thread t1(setNum, std::ref(mi),100);
	std::thread t2(printNum, std::ref(mi));
	std::thread t3(printNum, std::ref(mi));


	t0.join();
	t1.join();
	t2.join();
	t3.join();

	std::cout << "final num: " << mi.num << std::endl;
}

//shared mutex는 일반적인 mutex와는 다르게 Shared Lock이란 기능을 가지고 있다,
//즉 그 Lock을 공유하기 때문에 락을 공유하는 스레드들이 임계영역으로 들어가고 
//모든 스레드들이 그작업을 종료해야 lock(shared)이 해제 

//read Wrtie mutex가 대표적인 예

//기존의 mutex lock은 오직 한개의 스레드만 메모리 영역에 접근이 가능하다,
//그런데 접근할 때 read() 냐 Write()에따라 최적화가 더가능 하다,

//만약 모든 스레드가 Write라면 mutex_lock을 건다, 
//그런데 만약 모든 스레드가 Read operaion 이라면 다 접근 가능해도 된다,

//Write -> exclusive lock을 
//Read ->  shared lock을 사용한다, 

