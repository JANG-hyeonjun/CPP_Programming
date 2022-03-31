// Modern_CPP_std_dataRace.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>

int num = 0;

void plus10000()
{
    for (int i = 0; i < 10000; i++)
    {
        num++;
    }
}

int main()
{
   
   std::thread t1(plus10000);
   std::thread t2(plus10000);
   
   t1.join();
   t2.join();
   
   std::cout << "num: " << num << std::endl;
   //결과가 20000인것은 너무나도 자명하다 왜냐면 싱글스레드 기반으로 동작된 것이니
   //그러면 이것을 thread를 적용하면 다음과 같이 data race가 일어난다, 
   
   //이를 확인하려면 /fsanitize를 사용해서 디버깅 모드를 걸면 잡아주게 된다,


   return 0;
}

