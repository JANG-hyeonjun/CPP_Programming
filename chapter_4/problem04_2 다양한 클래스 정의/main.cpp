#include <iostream>


using namespace std;

class Point{
private:
    int xpos,ypos;
public:
    void Init(int x,int y){
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const{
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};
class Circle{
private:
    int rad;
    Point center;
public:
    void Init(int x,int y,int r){
        rad = r;
        center.Init(x,y);
    }
    void showCircleInfo() const{
        cout <<"radius : " << rad << endl;
        center.ShowPointInfo();
    }
};

class Ring{
private:
    Circle inCircle;
    Circle outCircle;
public:
    void Init(int inner_x,int inner_y,int inner_radius,int outer_x,int outer_y,int outer_radius)
    {
        inCircle.Init(inner_x,inner_y,inner_radius);
        outCircle.Init(outer_x,outer_y,outer_radius);
    }
    void ShowRinginfo() const{
        cout << "Inner Circle Info..." << endl;
        inCircle.showCircleInfo();
        cout << "Outer Circle Info..." << endl;
        outCircle.showCircleInfo();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRinginfo();
    return 0;
}
