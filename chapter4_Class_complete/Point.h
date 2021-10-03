//
// Created by 장현준 on 2021/07/31.
//

#ifndef CHAPTER4_CLASS_COMPLETE_POINT_H
#define CHAPTER4_CLASS_COMPLETE_POINT_H

class Point
{
private:
    int x;
    int y;

public:
    //bool InitMembers(int xpos , int ypos);
    //이것은 생성자를 넣은것이 아니라 초기화 해주는 멤버 함수를 완성한것이다.
    Point(const int &xpos,const int &ypos);
    int GetX() const;
    int GetY() const;

    bool SetX(int xpos);
    bool SetY(int ypos);
};


#endif //CHAPTER4_CLASS_COMPLETE_POINT_H
