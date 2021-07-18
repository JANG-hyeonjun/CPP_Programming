//
// Created by 장현준 on 2021/07/18.
//
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
    int *lenth = new int;
    char *str = new char[100];

    strcpy(str,"my name is hyeonjun");
    printf("%s\n", str);
    *lenth = strlen(str);
    printf("%d\n",*lenth);
    strcat(str," and i love play the drum");
    printf("%s\n",str);
    if(strcmp(str,"hello") == 0)
        printf("same\n");
    else printf("not same\n");


    return 0;
}

