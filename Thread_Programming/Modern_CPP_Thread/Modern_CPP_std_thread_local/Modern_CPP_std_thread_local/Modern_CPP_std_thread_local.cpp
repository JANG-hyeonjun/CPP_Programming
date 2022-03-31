// Modern_CPP_std_thread_local.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>

//thread local은 스레드 라이프 사이클까지 유지
//int globalNum = 0;
//thread_local int tlNum = 0;

//이는 스레드 별로 스태틱한 변수를 요할때 사용한다, 
//thread 별로 싱글톤과 같은 오브젝트를 만들떄 사용 

void fn()
{
    static int globalNum = 0;
    thread_local int tlNum = 0;
    
    int fnNum = 2;

    std::cout << "globalNum" << globalNum << std::endl;
    std::cout << "thLocalNum " << tlNum << std::endl;

    globalNum++;
    tlNum++;

}


int main()
{
    using namespace std::chrono_literals;

    int mainNum = 1;

    std::thread t1(fn);
    std::this_thread::sleep_for(1s);
    std::thread t2(fn);

    t1.join();
    t2.join();


}

