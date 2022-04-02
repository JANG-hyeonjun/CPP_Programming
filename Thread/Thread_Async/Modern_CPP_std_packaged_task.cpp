// Modern_CPP_std_packaged_task.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>

int add1(int n)
{
    std::cout << std::this_thread::get_id() << std::endl;
    return n + 1;
}

int main()
{
    // std::async 방법과 
    // std::feature,promise 쌍을 만들어 다른 스레드에 할당 
    std::packaged_task<int(int)> add1Task(add1);
    std::future<int> fut = add1Task.get_future();
    std::cout << std::this_thread::get_id() << std::endl;
    
    
    std::thread t1(std::move(add1Task),42);
    //패키지 테스크 오브젝트는 카피가 불가능 

    std::cout << "ret: " << fut.get() << std::endl;

    //그러면  auto fut1 = std::async(add1,42)와 다를게 없는것 아닌가?
    //1.위의 문장은 실행될때 policy가 std::launch::async로 실행 -> add1 함수가 비동기적으로 그순간 실행
    //1. 그러나 패키지드 태스크는 나중에 태스를 실행 시킬때 그 태스크가 실행 
    //2. async는 사용자 어떤 스레드에 함수를 매칭 시킬지 정할수가 없다, 
    //2. 하지만 패키지 태스크는 이를 지정 가능하다는 것이다, 
    t1.join();

}

//packeged task는 callable 오브젝트를 wrap하는 템플릿 클래스 
//람다함수 기존함수 콜러블 오브젝트 비동기적으로 부를수있는 래퍼 라고 생각해라 




