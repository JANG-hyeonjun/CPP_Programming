// FirstOperationOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#if 0
#include <iostream>


class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0,int y = 0) : xpos(x),ypos(y)
    { }
    void ShowPosition() const
    {
        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
    }
    Point operator+(const Point& ref)
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);

    //Point pos3 = pos1.operator+(pos2);
    Point pos3 = pos1 + pos2;
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}


#endif
