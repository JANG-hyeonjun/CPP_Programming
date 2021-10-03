#include <iostream>

using namespace std;


class AAA{
private:
    int num;
public:
    AAA() : num(0){}
    AAA& CreateInitObj(int n) const
    {
        AAA * ptr = new AAA(n);
        //이렇게 하면 객체를 생성하는 과정에서 생성자가 호출된다.
        // 객체가 되기 위해서는 반드시 생성자가 호출되어야한다.
        //이 예제는 private로 선언된 생성장를 통해서도 객체가 가능하다는것을 보여준다.
        return *ptr;
    }
    void ShowNum() const {cout << num << endl;}
private:
    AAA(int n) : num(n) {};
};

int main() {

    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA &obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    return 0;
}
