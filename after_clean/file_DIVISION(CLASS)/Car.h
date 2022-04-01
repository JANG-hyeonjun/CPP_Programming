//
// Created by 장현준 on 2021/07/24.
//

#ifndef FILE_DIVISION_CLASS__CAR_H
#define FILE_DIVISION_CLASS__CAR_H

namespace CAR_CONST
{
    enum{
        ID_LEN = 20,MAX_SPD = 200,FUEL_STEP = 2,
        ACC_STEP = 10 ,BRK_STEP = 10
    };
}

class Car{
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

#endif //FILE_DIVISION_CLASS__CAR_H
