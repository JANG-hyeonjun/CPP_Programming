// Modern_CPP_scoped_static_safeSingleton.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>


//scoped static init -> 병렬 프로그래밍을 하는데 있어 상당히 중요한 개념 
//이를 이해하면 멀티 스레드 환경에서 안전하게 싱글톤을 init할수 있다,

////////////scoped static////////////////

class Singleton
{
public:
	static Singleton& getInstance()
	{
		static Singleton sObj;
		return sObj;
	}
	//copy constructor, copy assign = delete(제거)하는 제외 
	//공부를 해보니 클래스가 로딩될떄 static 제어자에 의해 미리 인스턴스를 생성하는 방식을 사용한것같다,
	// 참고 https://simyeju.tistory.com/121
	
	//말하고자 하는 static scope init을 사용하면
	//한번만 초기화 하기위해 mutex나 call_once를 사용할 필요는 없다는 것을 말하고 싶었던 것 같다,
};

class Cat
{
public:
	Cat()
	{
		std::cout << "meow" << std::endl;
	}
};

void fn()
{
	//static int i = 0;
	static Cat cat;
	//scoped static init은 lazy init을 한다.
	//lazt init이란 프로세스 진행중 함수가 불러졌을때 초기화 된다는 의미
	//C++11이후 부터 중요한것은 아무리 많은 스레드가 그 함수를 호출해도 scoped 되어있는 스태틱 오브젝트는
	//무조건 한번만 초기화 된다는 것이다, 

	//싱글톤은 프로세스 전체에서 오직 하나의 오브젝트만 생성할수 있는 객체
	//상세하게는 GoF(Gang of Four) 디자인 패턴 중 하나로 생성자가 여러 차례 호출되더라도 실제로 생성되는 인스턴스는 하나이고, 최초 생성 이후에 호출된 생성자는 최초에 생성한 객체를 리턴하는 형태

	//중요한것은 scoped static을 활용하면 thread safe 한 싱글톤 클래스를 만들 수 있다는 것이다, 
	//스레드 세이프 하다는것은 멀티 스레드 환경에서 동작해도 원래 의도한 형태로 동작하느 코드를 
	//스레드 세이프 하다고 한다.


}

int main()
{
	/*fn();
	fn();
	*///이렇게하면 데이터(static 영역에 초기화 되기 때문에) 
	//아무리 함수를 불러도 만들어지는것이 아니라 그것을 게속 가져오거나 이용

	std::cout << "Process start" << std::endl;
	std::thread t1(fn);
	std::thread t2(fn);
	
	t1.join();
	t2.join();

}

