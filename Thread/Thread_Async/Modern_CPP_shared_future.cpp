// Modern_CPP_shared_future.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>
#include <thread>
#include <vector>


void fn(std::shared_future<int> fut)
{
	std::cout << "num: " << fut.get() << std::endl;
}

int main()
{
	using namespace std::chrono_literals;

	std::promise<int> prms;
	//std::future<int> fut = prms.get_future();
	std::shared_future<int> fut = prms.get_future();
	
	//std::jthread t(fn,std::move(fut));	
	std::vector<std::jthread> threads;
	for (int i = 0; i < 5; i++)
	{
		threads.emplace_back(fn, fut);
	}

	
	std::this_thread::sleep_for(1s);
	prms.set_value(42);

}
//원래 future는 하나만 매핑 되는 개념이나 promise가 쓴 데이터를 읽어올때 여러 future 가 읽어야 할수 있다,
//그럴때 사용한다, 
