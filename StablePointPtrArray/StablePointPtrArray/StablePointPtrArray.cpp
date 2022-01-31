// StablePointObjArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <ostream>

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend std::ostream& operator<<(std::ostream& os, const Point& pos);
    friend std::ostream& operator<<(std::ostream& os, const Point* pos);
};

//문제 11-2 풀이
std::ostream& operator<<(std::ostream& os, const Point* pos)
{
    os << '[' << pos->xpos << ", " << pos->ypos << ']' << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
    return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointArray
{
private:
    POINT_PTR* arr;
    int arrlen;
    BoundCheckPointArray(const BoundCheckPointArray& arr) { }
    BoundCheckPointArray operator=(const BoundCheckPointArray& arr) { }
public:
    BoundCheckPointArray(int len) : arrlen(len)
    {
        arr = new POINT_PTR[len];
        //이렇게 하면 생성자가 호출되는데 
        //인자를 받지 않는 void 생성자의 호출을 통해서
        //배열요소를 이루는 객체가 생성 되므로 13행에 정의된 생성사에 설정된 
        //디폴트값 에의해 객체의 모든 멤버가 0으로 초기화 된다.
    }
    POINT_PTR& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR operator[](int idx) const
    {
        if (idx < 0 || idx >= arrlen)
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
    ~BoundCheckPointArray()
    {
        delete[]arr;
    }
};
int main()
{
    BoundCheckPointArray arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    //Point 객체의 주소값을 저장하는 방식이다. 
    //이렇게 객체의 주소값을 저장하는경우 Deep Copy 와 Shallow Copy냐의 문제를 고민할 필요가 없다. 



    for (int i = 0; i < arr.GetArrLen(); i++)
    {
        std::cout << (arr[i]);
    }

    //대신 이렇게 delete를 해주어야한다.
    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }

    return EXIT_SUCCESS;
}

