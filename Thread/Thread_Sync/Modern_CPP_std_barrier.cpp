// Modern_CPP_std_barrier.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <Windows.h>
#include <iostream>
#include <barrier>
#include <thread>
#include <vector>

void print()
{
    std::cout << " phase completion" << std::endl;
}

std::barrier barrier(3,print);

void fn()
{
    std::cout<< "1" << std::flush;
    barrier.arrive_and_wait();
    std::cout<< "2" << std::flush;
    barrier.arrive_and_wait();
    std::cout<< "3" << std::flush;
    
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i++)
    {
        threads.emplace_back(std::thread(fn));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
    std::cout << std::endl;
}
//베리어란 여러 스레드 들이 차단 되었을때 어떠한 조건에 의해 
//베리어가 동작하게 되고 막혔던 스레드들이 진행한다,

//또 베리어는 래치와 다르게 내부 카운터가 리셋이 된다, 

//초기 카운터 value로 부터 0이 되기 까지의 구간을 페이즈라고 한다, 
//페이즈가 0이 되었을떄 페이즈 컴플리션 스텝이 실행 그 스텝에서 임의의 함수를 실행 할수 있다,

