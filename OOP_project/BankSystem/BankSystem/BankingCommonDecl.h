#pragma once


#include <iostream>
#include <cstring>

const int NAME_LEN = 20;

//프로그램 사용을 위한 선택 메뉴 구성 
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급 
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };