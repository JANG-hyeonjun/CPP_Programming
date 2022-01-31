// ArrayClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>


class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }
    ~BoundCheckIntArray()
    {
        delete[]arr;
    }
};


int main()
{
    BoundCheckIntArray arr(5);

    for (int i = 0; i < 5; i++)
    {
        arr[i] = (i + 1) * 11;
    }
    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return EXIT_SUCCESS;
}

