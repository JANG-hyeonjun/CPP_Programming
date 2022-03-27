// Modern_CPP_std_thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


std::thread gThread;

void fn()
{
    std::cout << std::this_thread::get_id()<< std::endl;
}

void thread_Caller()
{
    //std::thread t1(fn);
    //t1.detach();
    //이렇게 하면 t1 쓰레드를 메인 쓰레드로 부터 분리하면 다시 커뮤니케이션 하기 힘들다는점
    //그래서 detach는 안쓰는것이 좋다. 
    //그래서 이럴땐 쓰래드를 전역으로 선언 

    //gThread = std::thread(fn);

}

int main()
{
    
    
    //std::thread t1(fn);
    // Constructor // 
    //1.std::thread의 생성자는 아무것도 인자를 안주고 생성 해도 되지만 이는 플로우가없다.
    //2.그래서 이를 의미있게 사용하려면 실질적으로 함수를 인자로 주어 생성을 해야한다.
    //3. move를 통해 새로 쓰레드를 할당해주는것도 가능하다. 
    //std::thread t2{ std::move(t1) };

    //t1.join();
    //Join //
    // 전반적인 과정 메모리 그러니까 램에 main함수 Stack에 std::thread가 만들어지고
    // fn을 실행 시키기 위한 새로운 스레드를 만든다. 
    // 이어서 이 join이란 함수를 통해 스레드가 종료될때 까지 기다려주는것이다. 


    //detach
   // thread_Caller();
   // std::this_thread::sleep_for(std::chrono::seconds(3));
   // gThread.join();
   //// std::cout << "joinable: " << t1.joinable() << std::endl;
    // 그런데 특히하게 joinable 함수가 true이면 스레드가 main이 먼저 메모리 해제 될테니까
    //  terminate란 함수를 동작 시키는 것이다.

    //그 밖의 다양한 기능 
   // std::cout << "#threads" << std::thread::hardware_concurrency() << std::endl;

    //지금 까지는 쓰레드를 스택에만 만들었지만 사실 동적으로도 만들수 있다.

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(std::thread(fn));
    }


    for (auto& thread : threads)
    {
        thread.join();
    }

    return 0;
}

