// JsonParse.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h" 



int main()
{
    std::vector<int> USER_VAL = { 4,50,0,52,14,15,17,21,41 };

    rapidjson::Document document;
    document.SetArray();

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    for (int i = 0; i < USER_VAL.size(); i++)
    {
        document.PushBack(USER_VAL.at(i), allocator);
    }
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);

    printf("JsonData1 = %s", strbuf.GetString());
}


