#include <iostream>
#include <vector>
#include <algorithm>

typedef  std::wstring oss_string;

struct context_info
{
    oss_string context;
    oss_string  date;
    oss_string who;
};
std::vector<context_info> test;


//클래스 함수 헤더부 문제인가
//connect 함수에서 선언은 문제가 없다고 하셨다 그렇다는건 헤더부의 선언된 함수를 cpp가 인식을 못하는 거라고 볼수 밖에 없다 c2661
void get_info(oss_string s1,oss_string s2,oss_string s3)
{
    struct context_info temp;
    temp.context = s1;
    temp.date = s2;
    temp.who = s3;

    test.emplace_back(temp);
}

int main() {


    //string to wstirng을 넣어서 다시 테스트

    struct context_info temp;
    temp.context = L"내용 입력 테스트 ";
    temp.date = L"2022_1_30";
    temp.who = L"A clinic";

    get_info(temp.context,temp.date,temp.who);

    for(auto it : test)
    {
        std::wcout << it.date<<" "<<it.who << std::endl;
    }
    //잘들어가는데  람다식 connect함수에서는 왜안들어가는건지
    //아무래도 안들어가는 이유는 그렇다면 정의부의 함수를 받아들이지 못하는것이다.
    // 만약 담기는걸 월요일날 해결 하면 label에 이 객체를 담아서 오른쪽 왼쪽에 담는다.

    return 0;
}
