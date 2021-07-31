//
// Created by 장현준 on 2021/07/24.
//

#include <iostream>
#include <cstring>
#include "CarInline.h"
using namespace std;

void Car::InitMembers(char *ID, int fuel) {
    strcpy(gamerID,ID);
    fuelGauge=fuel;
    curSpeed = 0;
}
void Car::Accel() {
    if(fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if((curSpeed+CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}