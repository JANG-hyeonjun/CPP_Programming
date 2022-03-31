// Modern_CPP_std_safeMutex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>



struct MInt
{
	std::mutex mtx;
	int num = 0;
};

void plus1(MInt& mi)
{
	
	const std::lock_guard<std::mutex> lock(mi.mtx);
	//이렇게 하면 아래가 임계영역 (critical Section)으로 지정되면서 해당 스코프가 끝나면 뮤텍스 해제
	//mi.mtx.lock();
	mi.num++;
	//실제로는 이렇게 lock 과 unlock을 사용하면 코딩중에 버그가 들어가기 쉽다.
	// 실제로 이렇게 되면 unlock를 하고 리턴 되어야한다.
	//혹은 어떤 함수가 예외를 던져야할떄 mutex를 언락하기 전에 함수가 해제 되거나 하는 문제
	//이러한것을 해결하기 위해 mutext lock guard를 사용 한다, 


	/*if (mi.num == 10)
	{
		mi.mtx.unlock();
		return;
	}
	
	throw 
	이런 상황이 종료 되어도 스코프를 벗어나면 뮤텍스가 해제 된다는것이 보장 
	*/
	
	//만약 해당 부분 뒤에 바로 뮤텍스가 해제 되기를 원하면 scope로 감싼다, 
	//이와 같이 
	//scoped_lock
	//unique_lock
	//shared_lock
	//RAII idiom을 따르는 락 매니지를 사용하는것이 좋다. 

	//mi.mtx.unlock();
	

	

}

int main()
{
	MInt mi;
	std::thread t1(plus1, std::ref(mi));
	std::thread t2(plus1, std::ref(mi));

	t1.join();
	t2.join();

	std::cout << "num: " << mi.num << std::endl;
}

