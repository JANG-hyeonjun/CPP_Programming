// Modern_CPP_비동기호출주의점.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>

//thread_local int localInt = 0;
//
//int add1(int n)
//{
//    return n + 1;
//}
//
//void fn()
//{
//    std::cout << ++localInt << " ";
//}
//
//int main()
//{/*
//    int num = 42;
//
//    std::future<int> fut = std::async(std::launch::async, add1, num);
//    int ret = fut.get();
//    std::cout << "ret: " << ret << std::endl;*/
//    for (int i = 0; i < 100; i++)
//    {
//        std::async(std::launch::async, fn);
//    }
//
//    
//}


//이 async 자체는 비싼 연산 이 함수의 리턴 타입 퓨처를 통한 커뮤니케이션 채널은 
//힙 할당,해제 뮤텍스 ,컨디션 베리어블을 내장 
//또 이함수를 호출할 때 새로운 스레드를 매번 생성 소멸시키기위해 비싼연산이 더비싸짐 

//또 launch policy를 생각해야한다, 여기에 특별한 정책을 넘기지 않으면 
//deffered policy 샤로운 스레드를 생성시키거나 아니면 메인 스레드에서 lazy evaluation이 벌어짐 

//이렇게 std::launch를 비동기로 주어도 라이브러리 구현 마다 실행이 다르다는점을 알아야한다, 

//libstdc++은 비동기로 실행하는 태스크를 new thread로 해서 실행  
//msvc stl은 내부적으로 thread pool 사용 -> 더 복잡한 구조의 스레드를 재실행 

//떄문에 각 스레드에 바운딩 되는 thread_local 을 async와 사용하게 되면 예상치못한 결과를 얻음 

//그래서 std:;async를 사용할떄는 callable 오브젝트를 태스크로만 봐라보면서 코딩 


//////////////future 소멸자 ///////////
using namespace std::chrono_literals;

void fn1s()
{
	std::this_thread::sleep_for(1s);
	std::cout << "fn1s" << std::endl;
}

void fn2s()
{
	std::this_thread::sleep_for(2s);
	std::cout << "fn2s" << std::endl;
}

int main()
{
	/*auto fut1 = std::async(std::launch::async, fn1s);
	auto fut2 = std::async(std::launch::async, fn2s);*/

	//이렇게 생성하는것을 fire and forget이라고 한다, 

	//~future()
	std::async(std::launch::async, fn1s);

	//~future() 우리눈엔 보이지 않지만 이런게 내부적으로 실행 
	std::async(std::launch::async, fn2s);


}