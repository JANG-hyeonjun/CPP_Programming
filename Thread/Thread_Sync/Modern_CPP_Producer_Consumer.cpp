// Modern_CPP_Producer_Consumer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

class StrStack
{
public:
	//producer 
	void addStr(std::string s)
	{
		{
			std::lock_guard<std::mutex> lck(mMtx);
			mStrs.emplace_back(std::move(s));
		}
		mCv.notify_one();
	}
	//consumer
	std::string getStr()
	{
		std::unique_lock<std::mutex> lck(mMtx);
		while (mStrs.empty())
		{
			mCv.wait(lck);
		}
		std::string s = std::move(mStrs.back());
		mStrs.pop_back();
		lck.unlock();
		return s;
	}
private:
	std::vector < std::string> mStrs;
	std::mutex mMtx;
	std::condition_variable mCv;
};


int main()
{
	StrStack strStack;
	
	/*strStack.addStr("nocope");
	std::cout << strStack.getStr() << std::endl;*/

	std::thread t1([&]() {
		strStack.addStr("nocope");
		});

	std::thread t2([&]() {
		strStack.addStr("meow");
		});

	std::thread t3([&]() {
		//while(1)
		// 하나만 처리 할수도 있고 while문을 추가하면 계속 호출되니까 wait 상태로 대기 
		//이를 시간을 두고하면 몬스터 생산이나 어떠한 몹을 리젠 시키는대 사용할수 있는것이다, 
		std::cout << strStack.getStr() << std::endl;
		});

	/*std::thread t4([&]() {
		std::cout << strStack.getStr() << std::endl;
		});*/

	t1.join();
	t2.join();
	t3.join();
	//t4.join();
}

//생산자 소비자 패턴은 추상적 패턴이라 만드는 방법이 다양하다.
//이 패턴은 멀티 스레드 패턴을 사용할때 굉장히 많이쓰는 패턴이다, 

//여러 스레드들이 공유가 되는 자료구조(job Queue)가 있다고 하자 그안엔 job이 하나씩 할당 
//그 job Queue에 잡을 추가하는 스레드 그리고 이를 처리하는 스레드 producer _ consumer

//근데이걸 왜 하냐 왜 스레드를 나누어서 진행하냐면 producer 가 넣는것이 빨라 1초에 2개 
//근데 소비자 1초에 1개씩 처리하면 당연히 자료구조 오버플로 현상이 일어난다, 
//그럴때 만약 스레드를 이용해서 진행하면 효율적일 것이다, 

//그래서 가운데 자료구조를 기준으로 동기화 테크닉이 필요한것이다, 

//우리가 그동안 배운걸 활용한다고 하면 producer는 공유메모리에 write 하므로 당연히 뮤텍스가 필요하고
//가져가는 consumer에게 시그널을 주어야하니 conditional variable또한 필요하다, 

//반대쪽 consumer는 하나만 가져가서 처리할때 다른 스레드가 개입하면 안되니까 뮤텍스가 필요하다,
//잡큐가 비어있어서 wati 상태로 대기하다가 일어나야하는것이 효율적 그래서 cv wait이 필요 

//이번엔 stack을사용해볼것 job Queue가 아닌 string stack을 사용해볼것 