//
// Created by 장현준 on 2021/07/31.
//

#ifndef CHAPTER4_CLASS_COMPLETE_RECTANGLE_H
#define CHAPTER4_CLASS_COMPLETE_RECTANGLE_H

#include "Point.h"

class Rectangle{
private:
    Point upLeft;
    Point lowRight;

public:
    //bool InitMembers(const Point &ul,const Point &lr);
    Rectangle(const int &x1, const int &y1,const int &x2,const int &y2);
    void ShowRecInfo() const;
};

#endif //CHAPTER4_CLASS_COMPLETE_RECTANGLE_H
