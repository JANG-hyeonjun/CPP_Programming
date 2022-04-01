// Modern_CPP_std_mutext.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int num = 0;
void plust10000()
{
    mtx.lock();
    for (int i = 0; i < 10000; i++)
    {
        num++;
    }
    mtx.unlock();
}

void printThreadID()
{
    std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    /*std::thread t1(printThreadID);
    std::thread t2(printThreadID);*/

    //std::thread t1(plust10000);
    //std::thread t2(plust10000);

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(std::thread(plust10000));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    //t1.join();
    //t2.join();

    std::cout << num << std::endl;

    return 0;
}
//data race -> 두개이상의 스레드가 어떠한 메모리에 접근 하여 Writing을 하였을때 생기는 문제

//Lacc Condition -> 두개 이상의 스레드가 어떠한순서로 실행됬는가 에따라 다른결과를 보여주는것 
// 스레드의 타이밍에 따라 결과 값이 달라지는것이다. 

//이를 해결하기 위한것이 mutex 중요한것은 스레드가 먼저 블락 되었다고 해서 반드시 다음에 
//Lock를 획득하는것은 아니라는 것이다. 