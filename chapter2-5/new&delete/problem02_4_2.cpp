//
// Created by 장현준 on 2021/07/18.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    for(int i =0; i < 5; i++)
    {
        int random = rand() % 100;
        printf("%d\n",random);

    }
    return 0;
}