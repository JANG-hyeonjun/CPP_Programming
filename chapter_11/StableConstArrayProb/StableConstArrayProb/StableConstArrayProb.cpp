// ArrayClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>


class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) { }
    BoundCheckIntArray operator=(const BoundCheckIntArray& arr) { }
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
    int operator[](int idx) const
    {
        if(idx < 0 || idx >= arrlen)
        {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const
    {
        return arrlen;
    }
    ~BoundCheckIntArray()
    {
        delete[]arr;
    }
};

void ShowAllData(const BoundCheckIntArray& ref)
{
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++)
    {
        std::cout << ref[idx] << std::endl;
        //여기서 컴파일 에러가 나는 이유는 
        //연산자 오버로딩 ref.operator[](idx)를 호출하는데 
        //class안의 연산자 오버로딩함수는 const함수가 아니다. 
        //그러면 우리는 이를 어떻게 해결해야하는가
        //const의 선언유무에 따라 함수 오버로딩이 가능하다.
        //즉 위와 같이 해결이 가능하다. 
    }
}

int main()
{
    BoundCheckIntArray arr(5);

    for (int i = 0; i < 5; i++)
    {
        arr[i] = (i + 1) * 11;
    }
#if 0
    for (int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << std::endl;
    }
#endif
    ShowAllData(arr);
    return EXIT_SUCCESS;
}

