#include <iostream>


using namespace std;
//const 참조자와 const 포인터의 개념
int main() {
    const int num = 12;
    const int *ptr = &num;
    const int *(&ptr2) = ptr;

    cout << *ptr << endl;
    cout << *ptr2 << endl;
    return 0;
}
