#include <iostream>

using namespace std;

void value_Increase(int &ref1){
    ref1++;

}

void value_sign(int &ref2){
    ref2 = 0 - ref2;
}

int main() {
    int val1 = 10;
    int val2 = 20;
    value_Increase(val1);
    value_sign(val2);
    cout << "(1): "<< val1 << endl;
    cout << "(2): "<< val2 << endl;
    return 0;
}
//문제 2 정답
/*
 참조자는 상수를 선언 할술 없기 때문에 매개 변수의 인자로는 반드시 변수가 와야 한다.
 그런데 다음과 같이 SwapBYRef(23,45)로 줄 경우  위의 조건과 어긋나게 된다.
 */