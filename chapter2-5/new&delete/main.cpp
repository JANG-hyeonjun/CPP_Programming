#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char * MakeStrAdr(int len)
{
    char * str = (char*)malloc(sizeof(char) * len);
    return str;
}

int main() {
    char *str = MakeStrAdr(20);
    strcpy(str,"I am so happy~");
    cout << str << endl;
    free(str);
    return 0;
}

// 이렇게 하면 단점이 생긴다.
/*
 * 1.할당의 대상의 정보를 무조건 바이트 크기로 전달해야한다.
 * -> 함수를 호출 20 단위로 주어한다라고 작성했듯이
 * 2. 반환형이 void형 이기에 적절한 형 변환을 거쳐야 한다.
 * 잊지말자 나만이 정답이란는 오만 그 사람이 정답이 아니라는 편견을 버려야한다.
 * 나는 할 수 있다. 하루에 조금씩만 하자
 */