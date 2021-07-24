//
// Created by 장현준 on 2021/07/24.
//

#ifndef PROBLEM03_2_1_CAL_H
#define PROBLEM03_2_1_CAL_H

class Calculator{
private:
    double result;
    int ADD_num;
    int MIN_num;
    int MUL_num;
    int DIV_num;
public:
    void Init();
    double Add(double num1,double num2);
    double Div(double num1,double num2);
    double Min(double num1,double num2);
    double MUl(double num1,double num2);
    void showOpCount();
};

#endif //PROBLEM03_2_1_CAL_H
