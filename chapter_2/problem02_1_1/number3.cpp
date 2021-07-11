//
// Created by 장현준 on 2021/07/11.
//

#include <iostream>

using namespace std;

void SwapByRef2(int &ref1,int &ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main() {
    int num1 = 5;
    int *ptr1 =&num1;
    int num2 = 10;
    int *ptr2 = &num2;
    
    SwapByRef2(*ptr1,*ptr2);
    cout << "ptr1: "<< *ptr1 << endl;
    cout << "ptr2: "<< *ptr2 << endl;

    return 0;
}
