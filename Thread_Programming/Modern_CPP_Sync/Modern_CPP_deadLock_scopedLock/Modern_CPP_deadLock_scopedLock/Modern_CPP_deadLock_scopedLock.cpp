// Modern_CPP_deadLock_scopedLock.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>

//std::mutex mtx;
//std::recursive_mutex mtx;

std::mutex mtxA;
std::mutex mtxB;

//void fn()
//{
//    const std::lock_guard<std::recursive_mutex> lck(mtx);
//}
//
//void deadlockFn()
//{
//    const std::lock_guard<std::recursive_mutex> lck(mtx);
//    //const std::lock_guard<std::mutex> lck2(mtx);
//    //이렇게 하면 해제를 하지않고 선점한 상태로 뮤텍스를 또 기다린다.
//    //그러니 데드락인 것이다,
//
//    fn();
//    //self deadlock 상황이다,
//
//    //그런데 의도적으로 스레드가 자기 자신한테 락을 걸어야할 상황이 생길수도 있다.
//    //이러한것을 해결하기 위해 recursive_lock이 존재 
//}

void ab()
{
    //const std::lock_guard<std::mutex> lckA(mtxA);
    {
        const std::scoped_lock lck(mtxA,mtxB);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //const std::lock_guard<std::mutex> lckB(mtxB);
    }
}


void ba()
{
    //const std::lock_guard<std::mutex> lckA(mtxA);
    {
        const std::scoped_lock lck(mtxB,mtxA);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //const std::lock_guard<std::mutex> lckB(mtxB);
    }
}

//이러한 데드락을 해결하기 위한 방법중 하나는 mutex획득을 같은 순서로 걸어 줘야 한다,
//근데 실무를 항상 고려해보면 뮤텍스 많으면 이 순서 맞추는것을 계속 생각하며 코딩을 해야한다,
//이를 해결하기위해 도와주는 것이 scoped_lock 인데
//하나 그이상의 mutex를 RAII-style로 잠궈주는 mutex wrapper 
//그리고 여러 mutex가 주어지면 dead_lock을 회피 해주는 알고리즘이 탑재 되어 있다.

//그런데 이는 C++ 17이상 버전부터 사용 되는 것이기 때문에 만약 이전 버전에서 이와 같이 만들고 싶다면 
//std::lock 과 std::lock_guard를 혼합해서 사용해야 한다, 
/*
std::lock(e1.m,e2.m); //여기서 획득한 lock을 
std::lock_guard<std::mutex> lk1(e1.m, std:;adopt_lock);
std::lock_guard<std::mutex> lk2(e2.m, std:;adopt_lock);
언락을 해주어야 하기때문에 이렇게 만들어 줘야 한다,
*/

/// 정리 ////
// 1. 하나의 lock -> lock guard
// 2. 여러개의 lock -> scoped_lock 
// 두개 모두 스코프가 끝나면 mutex lock을 해제 한다, 

int main()
{
    std::thread t1(ab);
    std::thread t2(ba);
    t1.join();
    t2.join();
    
    std::cout << "bye" << std::endl;
}


