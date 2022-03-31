<<<<<<< HEAD
﻿//// Modern_CPP_std_jthread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include <thread>
//
////std thread 를 보안 하기 위해 만들어진 C++ 20 의 jthread 
////여기서 j는 joining이다.
//
//
//void fn(std::stop_token stoken)
//{
//	for (int i = 0;  ; i++)
//	{
//		using namespace std::chrono_literals;
//		std::this_thread::sleep_for(1s);
//		std::cout << i << std::endl;
//		
//		if (stoken.stop_requested())
//		{
//			std::cout << "stop requiested" << std::endl;
//			return;
//		}
//	
//	}
//	//만약 이렇게 무한히 도는 반복문을 정지해야 한다면 스탑 토큰을 폴링 방식으로 사용한다,
//	//std::cout << "fn" << std::endl;
//}
//
//int main()
//{
//	//일반적인 스레드//////////
//	//std::thread t1(fn);
//	//t1.join();
//	//우리는 이러한 스레드를 사용할 때 join을 하거나 detach를 하지 않으면 문제가 일어난다.
//
//	//그래서 우리는 jthread를 사용한다.
//	std::jthread t1(fn);
//	t1.request_stop();
//	
//	//이렇게 코드를 진해함에 있어 오류가 나지 않는 이유는 
//	//메인 스레드에서 jthread가 없어질때 소멸자를 호출하는데 내부적으로 join이란 함수를 호출한다.
//	//jthread 오브젝트 를 통해 실행 되고 있는 스레드가 종료가 될때 까지 기다린뒤 제거 
//	
//	//그런데 스탑 리퀘스트를 작성하지않아도 된다, 그이유는 jthread 소멸자에서 join을 호출하기전 
//	// request_stop을 호출하기 때문이다. 
//
//	//~jthread() -> request_stop()-> join()
//	return 0;
//}
//
=======
﻿// Modern_CPP_std_jthread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>

//std thread 를 보안 하기 위해 만들어진 C++ 20 의 jthread 
//여기서 j는 joining이다.


void fn(std::stop_token stoken)
{
	for (int i = 0;  ; i++)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
		std::cout << i << std::endl;
		
		if (stoken.stop_requested())
		{
			std::cout << "stop requiested" << std::endl;
			return;
		}
	
	}
	
	//만약 이렇게 무한히 도는 반복문을 정지해야 한다면 스탑 토큰을 폴링 방식으로 사용한다,


	//std::cout << "fn" << std::endl;
}

int main()
{
	//일반적인 스레드//////////
	//std::thread t1(fn);
	//t1.join();
	//우리는 이러한 스레드를 사용할 때 join을 하거나 detach를 하지 않으면 문제가 일어난다.


	//그래서 우리는 jthread를 사용한다.
	std::jthread t1(fn);
	t1.request_stop();
	

	//이렇게 코드를 진해함에 있어 오류가 나지 않는 이유는 
	//메인 스레드에서 jthread가 없어질때 소멸자를 호출하는데 내부적으로 join이란 함수를 호출한다.
	//jthread 오브젝트 를 통해 실행 되고 있는 스레드가 종료가 될때 까지 기다린뒤 제거 

	//그런데 스탑 리퀘스트를 작성하지않아도 된다, 그이유는 jthread 소멸자에서 join을 호출하기전 
	// request_stop을 호출하기 때문이다. 

	//~jthread() -> request_stop()-> join()

	return 0;
}

>>>>>>> fd66164948751fec4442c9bae152aac1cf37cb22
