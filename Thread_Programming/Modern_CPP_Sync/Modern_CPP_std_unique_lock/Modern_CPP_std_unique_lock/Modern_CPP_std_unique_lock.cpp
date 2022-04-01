// Modern_CPP_std_unique_lock.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//



//lock guard와 비슷하면서 더많은 기능을 가지고 있는 unique_lock
//lock_guard는 scope 단위로 mutex를 해제 

#include <iostream>
#include <thread>
#include <mutex>

struct MInt
{
    std::mutex mtx;
    int num = 0;
};

std::unique_lock<std::mutex> unlockTest(std::unique_lock<std::mutex> lck)
{
    //그럼이는 어떠한 조건하에 락을 해제 시키는것도 가능하다. 
    if (true)
    {
        lck.unlock();
    }
    
    return lck;

}

void plus1(MInt& mi)
{
    //std::lock_guard<std::mutex> lock(mi.mtx);
    //lock guard는 실제로 카피 무브가 안되고 생성자와 소멸자 만 있다, 즉 제한적이란 말 
    std::unique_lock<std::mutex> lock(mi.mtx);
    //반면  unique_lock은 기능이더 많다. 훨씬 그리고 무엇보다 move가 된다는것이다, 
    //여기서 무브라는것은 어떠한 함수의 파라미터 도 가능하고 리턴으로도 보낼수 있다는 말이다,
    //위에 처럼 
    mi.num++;

    lock = unlockTest(std::move(lock));
    //이렇게 하는것이 중요한 이유는 이 mutex를 리소스라는 개념으로 관리가 가능하다는 것이다, 

    //그러면 결론적으로 언제 unique_lock을 쓰고 언제 lock_guard를 사용하느냐 
    // 1.언제나 처음 웬만하면 lock_guard를 사용하고 2. unique_lock만의 기능이 필요할때 사용
    //더많은 뮤텍스 기능이 필요하다면 사용하는것이 좋다. 

}


int main()
{
    MInt mi;
    std::thread t1(plus1, std::ref(mi));
    std::thread t2(plus1, std::ref(mi));
    
    t1.join();
    t2.join();

    std::cout << "num: " << mi.num << std::endl;
}

