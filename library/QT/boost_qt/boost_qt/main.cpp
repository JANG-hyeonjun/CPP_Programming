#include "boost_qt.h"
#include <QtWidgets/QApplication>

#include <stdio.h>
#include <iostream>
#include <crtdbg.h>
// boost�� asio���̺귯�� ũ�ν� �÷����� ����� ���̺귯��
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>
#if _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
using namespace std;
using namespace boost::asio;
using namespace this_thread;
using namespace chrono;
// ������ �����Լ�.
void threadTest()
{
    // �ݺ����� ���鼭 �ֿܼ� ���� ����Ѵ�.
    for (int i = 0; i < 4; i++)
    {
        cout << i << endl;
        sleep_for(microseconds(1));
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boost_qt w;
    
    
    // thread pool ���� thread �ִ� ������ �Ѱ��� �����Ѵ�.
    thread_pool* pool = new thread_pool(1);
    // ������ ����
    post(*pool, threadTest);
    // ������ ����
    post(*pool, threadTest);
    // ������ ����
    post(*pool, threadTest);
    // pool ���� ��� �����尡 ������ ������ ��ٸ���.
    pool->join();
    // �޸� ����
    delete pool;
    // �޸� ��üũ �Լ�.
    _CrtDumpMemoryLeaks();

    
    w.show();
    return a.exec();
}
