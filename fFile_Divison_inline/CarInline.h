//
// Created by 장현준 on 2021/07/24.
//

#ifndef FFILE_DIVISON_INLINE_CARINLINE_H
#define FFILE_DIVISON_INLINE_CARINLINE_H

#include<iostream>
using namespace std;

namespace CAR_CONST
{
    enum{
        ID_LEN = 20,MAX_SPD = 200,FUEL_STEP = 2,
        ACC_STEP = 10 ,BRK_STEP = 10
    };
}

class Car {
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public:
    void InitMembers(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

inline void Car::ShowCarState() {
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << endl;
    cout << "현재속도: " << curSpeed << endl << endl;
}

inline void Car::Break() {
    if(curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

#endif //FFILE_DIVISON_INLINE_CARINLINE_H
