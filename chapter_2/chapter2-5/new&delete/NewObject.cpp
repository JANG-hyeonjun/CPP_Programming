//
// Created by 장현준 on 2021/07/18.
//
#include <iostream>
#include <stdlib.h>

using namespace std;

class Simple
        {
        public:
            Simple(){
                cout << "I'm simple constructor!" << endl;
            }
};

int main()
{
    cout << "case1 :";
    Simple * sp1 = new Simple;
    cout << "case2: ";
    Simple * sp2 = (Simple*)malloc(sizeof(Simple) * 1);
    cout << endl << "end of main" << endl;
    delete sp1;
    free(sp2);
    return 0;
}
/*
 * new 연산자를 이용해서 할당된 메모리 공간도 변수로 간주하여 참조자 선언이 가능하다
 * 다음과 같은 코드도 동작하게 된다.
 * int *ptr = new int
 * int &ref = *ptr
 * ref = 20
 * cout << *ptr << endl;
 * 출력 결과는 20이다
 */