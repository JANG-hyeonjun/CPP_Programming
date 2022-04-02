// Modern_CPP_semaphore.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<2> sp(2);
//<최대 세마포어> (현재 개수) 


class RscManager
{
public:
    void createRsc()
    {
        mSp.acquire();
    }
    void removeRsc()
    {
        mSp.release();
    }
private:
    std::counting_semaphore<2> mSp{ 2 };

};


void waitFn()
{

    std::cout << "waiting" << std::endl;
    sp.acquire();
    std::cout << "re run" << std::endl;
}

void signalFn()
{
    std::cout << "signal" << std::endl;
    sp.release();
}

//void fn()
//{
//    sp.acquire(); //wait
//    std::cout << "semaphore region" << std::endl;
//    sp.release();
//    //리소스를 관리해주는 클래스를 만드는데에도 사용될수 있다.
//
//}

int main()
{
    /*std::thread t1(fn);
    std::thread t2(fn);
    std::thread t3(fn);

   
    t1.join();
    t2.join();
    t3.join();*/
    
    std::thread waitT(waitFn);
    std::thread signalT(signalFn);

    waitT.join();
    signalT.join();

}

//세마포어는 뮤텍스롸 같이 리소스의 제한을 두기 위해 사용하며 시그널 보낼떄도 사용
//세마포어는 내부에 카운트를 가지고 있다.

//뮤텍스 와 세마포어의 큰차이는 뮤텍스는 락을 거는 스레드와 이를 푸는 스레드가 같아야 하지만 
//하지만 세마포어는 다른 스레드가 acquire 할수도 있고 또 다른 스레드가 release할수 있다.
//그렇기에 시그널을 보내는 용도로도 사용할수 있다,