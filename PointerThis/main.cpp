#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {
            cout << "num=" << num << ", ";
            cout <<"address=" << this << endl;
    }
    void ShowSimpleData()
    {
        cout << num << endl;
    }
    SoSimple * GetThisPointer() {
        return this; //이 문장을 실행하는 객체의 포인터를 반환 해라
        //
    }
};

int main() {

    SoSimple sim1(100);

    SoSimple *ptr1 = sim1.GetThisPointer();
    //객체 sim1에 의해 반한된 this를 ptr1에 저장하고 있다. 이때 this는 SoSimple 의 포인터 임으로
    //SoSimple형 포인터 변수에 저장
    cout << ptr1 << ", ";
    ptr1 ->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple * ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2 ->ShowSimpleData();

    return 0;
}
