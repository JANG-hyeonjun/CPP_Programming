// FirstOperationOverloading.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>


class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
    }

    Point operator+=(const Point& ref)
    {
        xpos += ref.xpos;
        ypos += ref.ypos;
        return *this;
    }
    
    Point operator-=(const Point& ref)
    {
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }

    friend Point operator+(const Point& pos1, const Point& pos2);
    friend Point operator-(const Point& pos1, const Point& pos2);
    friend bool operator==(const Point& pos1, const Point& pos2);
    friend bool operator!=(const Point& pos1, const Point& pos2);
};



Point operator+(const Point& pos1, const Point& pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool operator!=(const Point& pos1, const Point& pos2)
{
    if (pos1.xpos != pos2.xpos || pos1.ypos != pos2.ypos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Point pos1(10, 20);
    Point pos2(5, 7);
    Point pos3(5, 7);

    //Point pos3 = pos1.operator+(pos2);
    //Point pos3 = pos1 + pos2;
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    (pos1 - pos2).ShowPosition(); //���� 1
    //(pos2 += pos3).ShowPosition(); //���� 2

    if (pos2 == pos3)
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;

    (pos2 += pos3).ShowPosition(); //���� 2
    //return *this��°� �ƹ����� ���������� �� Ŭ������ �ּҸ� �������ֱ⶧���� 
    //pos2�� ���� ������ ����ǰ� �ȴ�. 
    //2022.01.02 hj

    if (pos2 != pos3)
        std::cout << "not equal" << std::endl;
    else
        std::cout << "equal" << std::endl;

    return 0;
}

