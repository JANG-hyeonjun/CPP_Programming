// Modern_CPP_Async_intro.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>

int fn()
{
    std::cout << "async fn" << std::endl;
    return 42;
}


int main()
{
    std::future<int> fut = std::async(std::launch::async, fn);
    //비동기를 실행 할때 launch policy를 넘겨주어야하는데 
    //그것을 비동기적이라는 것으로 넘겨준다,
    const int num = fut.get();
    //만약 위에 future값이 준비가 되지않았다면 메인 스레드는 get 함수에서 weight상태가 되었다가 
    //future에 결과 값을 받았다면 넘버를 받고 자신의 일진행

    std::cout << "return num" << num << std::endl;
}

// 시간 자체가 오래걸리는 연산적으로 비싸거나 시스템 콜이 많다거나 다른 서버의 리스폰스를 기다린다거나
// 하는 함수를 다른 스레드 에게 맡기고 메인함수는 할일을 한다, 다른 스레드가 가져온 결과 값만 활용

//그래서 CPP는 태스크기반의 비동기 함수 호출 -> 주어진 함수를 태스크로 보고 그냥 이 태스크가 알아서 처리되도록
//추상화 시키는 것 

//그럼 개발자는 추상화된 라이브러리를 통해 비동기적으로 태스크를 진행 
//중요한건 task를 통해 만들어진 데이터가 태스크를 호출한 caller로 안전하게 패스하고 시그널을 보내냐인데
//이게 future 와 promise를 통해 구현할수있다,



