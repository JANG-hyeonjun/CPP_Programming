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