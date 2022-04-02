// Modern_CPP_Future_Promise.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

void fn(std::promise<int> prm)
{
    std::this_thread::sleep_for(1s);
    try
    {
        throw std::runtime_error("nocope");
    }
    catch (...)
    {
        prm.set_exception(std::current_exception());
    }
   // prm.set_value(42);
}

int main()
{
    std::promise<int> prms;
    std::future<int> fut = prms.get_future();


    std::thread t(fn, std::move(prms));

    try
    {
        const int num = fut.get();
    }
    catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() <<std::endl;
    }


   // prms.set_value(42);
    /*while (fut.wait_for(0.2s) != std::future_status::ready)
    {
        std::cout << "doing other work" << std::endl;
    }*/
   // const int num = fut.get();

   // std::cout << "num: "<< num << std::endl;
    t.join();
}

//비동기 함수의 리턴타입은 future 에이어서 promise 이들은 커뮤니케이션 채널을 만드는 하나의 쌍 
// 이채널을 통해 data,exception,signal data  -> promise에 data를 넣으면 future를 통해 데이터를 가져가는 방식


//이들은 같은 스레드에서 커뮤니케이션 해도 되고 다른 스레드에서 커뮤니 케이션 해도 된다, 
//중요한것은 future 와 promise 커뮤니케이션 채널 사이 안에 condition variable, mutex, shared memory가 숨겨져 있는것 

//그러면 커뮤니케이션 채널 사이안에 값이 들어올떄 까지 main 스레드가 블락상태로 있는것이아닌 
// 주기적으로 자신의 일을하면서 값이 있는지 체크

//그런데 이게 채널적이 약간 느리다 -> 라이브러리가 heap mutex cv ref_counter를 할당해야 하기 때문에 
//타입 크리티컬 한 곳에서는 사용하지 않는것이 좋다, 