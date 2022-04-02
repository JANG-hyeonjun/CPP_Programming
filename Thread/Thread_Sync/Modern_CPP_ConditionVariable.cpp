// Modern_CPP_ConditionVariable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

bool readyFlag = false; //shared variable 이자 condition variable이다, 이를 뮤텍스로보호
std::condition_variable cv;
std::mutex mtx;

void waitFn()
{
	std::cout << "wait" << std::endl;
	std::unique_lock<std::mutex> lck(mtx);
	while (!readyFlag)
	{
		cv.wait(lck);
	}
	//critical Section
	
	//wait thread가 여기를 만나면서 블락 상태가 되어짐 
	//이게 블락이 풀리기 위해서는 다른 스레드에서의 notify 시그널을 받아야 한다는 의미
	std::cout << "re run" << std::endl;

}

void signalFn()
{
	std::cout << "signal" << std::endl;
	{
		std::lock_guard<std::mutex> lck(mtx);
		readyFlag = true;
	}
	cv.notify_one();
}

int main()
{
	std::thread waitT(waitFn);
	std::thread signalT(signalFn);

	waitT.join();
	signalT.join();

}

//condition_var은 cocuuerency 개념과 생성 소비 패턴에도 사용
// 사용목적은 하나의 스레드에서 다른 스레드로 신호를 보낼때 사용 

//근데이 코드는 잘못되었다 만약 기다리기도 전에 시그널 스레드에서 notify_one을 보냈다면 
//그것은 Lost wakeup 현상이 벌어지는 것이다, 즉 block을 하기전에 이미 시그널이 보내졌기 때문에 
// block이 풀리지 않고 영원히 블락상태로 있게 되는것 

//이것을 해결 하기 위해 두 스레드간 shared_variable을 사용하는 것이다, 
//또한 이 shared variable을 여러 스레드의 접근으로 부터 보호하기 위해 mutex가 필요한것 

//또 이렇게 하는 이유는 surious wake_up을 방지 하기 위한것이다, 
