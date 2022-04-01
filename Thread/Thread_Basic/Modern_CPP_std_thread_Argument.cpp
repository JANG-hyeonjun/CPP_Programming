// Modern_CPP_std_thread_Argument.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <string>


//argument_ref
#if 0
void fn(int a, std::string& s)
{
	//여기서 신경 써야 할것은 ref 나 변수의 life cycle이란 것이다. 
	std::cout << a << s << std::endl;
}

int main()
{
	int num = 42;
	std::string s = "nocope";
	std::thread t1(fn, num, std::ref(s));
	t1.join();

}
#endif


//void fn(int& a)
//{
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	std::cout << a << std::endl;
//}
//
//void threadCaller(std::thread& t)
//{
//	int num = 42;
//	//fn(num);
//	t = std::thread(fn, std::ref(num));
//	t.join();
//}
//
//int main()
//{
//	std::thread t1;
//	threadCaller(t1);
//	//t1.join();
//	return 0;
//}

//이렇게하면 이상한 숫자가 나오게 된다.

//왜 그런것이냐 
//이유는 다음과 같다.
/*
* main 함수는 t1이란 스레드를 만든다. 스택에 
* thread caller를 통해 숫자 42도 스택에 할당
* 그리고 함수 fn을 실행 시키기 위해 새로운 스레드를 생성 그리고 이스레드는 main함수의 t1이 관리
* 근데 fn이 넘겨받은 숫자를 출력하려고 했는데 메인 thread 종료된 threadCaller 함수를 pop해서 메모리 영역에서 제거
* 이러한 이유때문에 쓰레드는 같은 스코프에서 조인을 해주는것이 안전하고 방어적인 프로그래밍 
*/


//get return value
//이렇게 말고 트릭이긴 한데 람다 함수를 써주면 어느정도 값을 넘겨 받는것 처럼 보일 수 있다. 
//int fn()
//{
//	return 3;
//}
//
//int main()
//{
//	int num = 0;
//	std::thread t1([&num]()
//		{
//			num = fn();
//		});
//	//std::thread t1(fn, std::ref(num));
//	t1.join();
//	std::cout << "retVal: " << num << std::endl;
//
//}

//Exception
int fn()
{
	throw std::runtime_error("error");
	//이렇게하면 문제는 에러가 다른 쓰레드에서 던저 졌다는것 
	//이를 해결하려먼 mutex나 atomic을 사용해야한다.
}

int main()
{
	try
	{
		std::thread t1(fn);
		t1.join();
	}
	catch (const std::exception&)
	{
		std::cout << "catched" << std::endl;
	}
}