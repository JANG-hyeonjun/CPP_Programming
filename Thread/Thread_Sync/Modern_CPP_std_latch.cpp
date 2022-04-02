// Modern_CPP_std_latch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <chrono>
#include <latch>
#include <thread>
#include <vector>


std::latch latch{ 3 };

void fn()
{
    std::cout << "decrease counter" << std::endl;
    std::cout << "wait " << std::endl;
    /*latch.count_down();
    latch.wait();
    */
    latch.arrive_and_wait();
    std::cout << "rerun" << std::endl;
}




int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i++)
    {
        using namespace std::literals;
        std::this_thread::sleep_for(500ms);
        threads.emplace_back(std::thread(fn));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

}

//latch는 한국어로 문 걸어 잠구는 장치
//스레들 wait 시키다가 일정 조건을 만족하면 문고리가 열리면서 스레드가 동작 

//풀리는 조건 카운터 베이스 -> 근데 세마포어오 다른점은 카운터 감소만 한다, 
//목적 스레드를 동기화 하는데 있으며 downward counter 이다. 

//latch의 카운터는 리셋 될수 없다, 그래서 래치 카운터가 -1이 되어버려서 
//마지막 wait은 깨지 않는다.

//또한 latch는 counter down 과 wait을 합친 arrive_and_wait 이 있다,