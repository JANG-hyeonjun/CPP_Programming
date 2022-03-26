//
// Created by 장현준 on 2021/07/18.
//
#include <iostream>

using namespace std;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1 , const Point &p2)
{
    Point * temp = new Point;
    temp ->ypos = p1.ypos + p2.ypos;
    temp ->xpos = p1.xpos + p2.xpos;
    return *temp;
}


int main(void)
{
    Point * p1 = new Point;
    Point * p2 = new Point;
   // Point *final = new Point;

    cin >> p1->ypos >> p1->xpos;
    cin >> p2->ypos >> p2->xpos;
    Point &final = PntAdder(*p1,*p2);

    cout << final.ypos<<' '<< final.xpos << endl;
    return 0;
}