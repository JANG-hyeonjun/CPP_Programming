// Modern_CPP_std_async.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>
#include <thread>

//void add1(std::promise<int> prms, int n)
//{
//    prms.set_value(n + 1);
//
//}

int add1(int n)
{
    /*using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);*/
    
    throw std::runtime_error("nocope");
    return n + 1;
}

int main()
{
    int num = 42;
    
    //std::promise<int> prms;
    try
    {
        std::future<int> fut = std::async(add1,num);
        int ret = fut.get();
        std::cout << "ret: " << ret << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    //std::jthread t(add1, std::move(prms), num);
}

//비동기 함수호출을 쉽게 만들어 주는 async를 실습
//lazy evaluation defeferred policy는 새로운 스레드를 할당하는 것이아니라 진행되고 있던 
//메인 스레드 에서 future객체.get()을 만났을때 함수를 호출하기때문에 lazy evaluation이라고 하는것 