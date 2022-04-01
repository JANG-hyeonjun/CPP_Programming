//// Modern_CPP_std_callOnce.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include <mutex>
//#include <thread>
//
//
//class Cat
//{
//public:
//    Cat()
//    {
//        std::cout << "init cat" << std::endl;
//    }
//    void speak()
//    {
//        std::cout << "meow" << std::endl;
//    }
//
//};
//
//std::once_flag flag;
//std::unique_ptr<Cat> cp = nullptr;
////예를들어 나는 cp 포인터를 한번만 초기화 하고싶은데 스레드가 많아서 여러번 초기화 하는게 걱정이라면
////call_once를 사용하면 된다, 
//
////이것이 가능하다는건 class에있는 멤버도 초기화 가능하다는것이다, 
//class zoo
//{
//private:
//    std::optional<Cat> mCat;
//    std::once_flag catInitFlag;
//};
//
//void print()
//{
//    std::cout << "printed" << std::endl;
//}
//
//void fn()
//{
//   // print();
//   //std::call_once(flag, print);
//    std::call_once(flag, []() {
//        cp = std::make_unique<Cat>();
//        });
//}
//
//int main()
//{
//    std::thread t1(fn);
//    std::thread t2(fn);
//    std::thread t3(fn);
//    std::thread t4(fn);
//    
//    //thread가 아무리 많아도 전체 프로세스에서 이함수를 오직한번만 부르게 하고싶다면
//    //call_once를 사용 
//    //이 call_once를 구현하기 위해서는 mutex와 boolean을 원래는 사용하여한다,
//    //flag를 확인하기 위해 mutex를 락을 하고 해제해 주어야한다,
//
//    //실제는 어떻게 쓰는가?
//    //답은 object initalizer에 사용한다.
//
//
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//
//    cp->speak();
//}
//   
////call_once 
//
////특별한 상황에서 프로그램의 mutex사용보다 더 최적화 하는 기법 
//// call once란 멀티 스레드 환경에서 어떤 콜러블 오브젝트나 함수가 오직한번만 실행되게 만들어주는 함수

