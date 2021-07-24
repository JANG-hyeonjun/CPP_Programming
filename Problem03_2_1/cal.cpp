//
// Created by 장현준 on 2021/07/24.
//
#include "cal.h"
#include <iostream>

using namespace std;

void Calculator::Init() {
    result = 0;
    ADD_num = 0;
    MIN_num = 0;
    MUL_num = 0;
    DIV_num = 0;
}
double Calculator::Add(double num1, double num2) {
    result = num1 + num2;
    ADD_num++;
    return result;
}
double Calculator::Min(double num1, double num2) {
    result = num1 - num2;
    MIN_num++;
    return result;
}
double Calculator::MUl(double num1, double num2) {
    result = num1 * num2;
    MUL_num++;
    return result;
}
double Calculator::Div(double num1, double num2) {
    result = num1 / num2;
    DIV_num++;
    return result;
}
void Calculator::showOpCount() {
    cout<<"덧셈: "<< ADD_num << " ";
    cout<<"뺄셈: "<<MIN_num<< " ";
    cout<<"곱셈: "<<MUL_num<< " ";
    cout<<"나눗셈: "<<DIV_num<< " ";
}