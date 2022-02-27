// NontypeTemplateParam.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template<typename T = int,int len = 7>
class SimpleArray
{
private:
    T arr[len];
public:
    T& operator[](int idx)
    {
        return arr[idx];
    }
    SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = ref.arr[i];
        }
        return *this;
    }

};

int main()
{
    SimpleArray <> i5arr1;
    for (int i = 0; i < 7; i++)
    {
        i5arr1[i] = i * 10;
    }
    SimpleArray <> i5arr2;
    i5arr2 = i5arr1;

    for (int i = 0; i < 7; i++)
    {
        std::cout << i5arr1[i] << ", ";
    }
    std::cout << std::endl;
    
    SimpleArray <int, 7> i7arr1;
    for (int i = 0; i < 7; i++)
    {
        i7arr1[i] = i * 10;
    }
    
    SimpleArray <int, 7> i7arr2;
    i7arr2 = i7arr1;
    
    for (int i = 0; i < 7; i++)
    {
        std::cout << i7arr2[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}

