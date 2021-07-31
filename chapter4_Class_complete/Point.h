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
    bool InitMembers(int xpos , int ypos);
    int GetX() const;
    int GetY() const;

    bool SetX(int xpos);
    bool SetY(int ypos);
};


#endif //CHAPTER4_CLASS_COMPLETE_POINT_H
