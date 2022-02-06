// MakeStringClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

//class design
class String
{
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+ (const String& s);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::ostream& os, String& s);
};

//class implementation
String::String()
{
	len = 0;
	str = NULL;
}
String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s); //target source
}
String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
//여기까지 생성자 오버로딩 3개
String::~String()
{
	if (str != NULL)
	{
		delete[]str;
	}
}
//소멸자 

//operator=의 대입을 깊은 복사로 진행하는 방향 
String& String::operator=(const String& s)
{
	if (str != NULL)
	{
		delete[]str;
	}
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	len += s.len - 1;
	//왜이렇게 할까? 길이가 뒤에 \0이 붙을 테니까 -> 아마 NULL이 두번 붙을꺼니까 하나를 제거해주는 것 
	//한줄도 그냥 넘기지 말자 지금이라도 매일같이 왜 그럴까를 고민하자 
	char* tempstr = new char[len];
	strcpy(tempstr,str);
	//원래꺼를 temp str에 복사
	strcat(tempstr, s.str);
	//그 뒤에 들어온걸 붙인다. 

	if (str != NULL)
	{
		delete[]str;
	}
	str = tempstr;
	return *this;
}
//연산자 오버로딩을 이용하면 다음과 같이 간단하게 코드를 작성할수도 있지만 객체를 하나 더만든다는점에서 컴퓨팅 성능을 고려
/*
String& String::operator+=(const String& s)
{
	*this = *this + s;
	return *this;
}
*/


bool String::operator==(const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s)
{
	//위에 있는 operator len += s.len -1; 과 char* tempstr = new char[len]은 아래 같이  
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr); // String temp = tempstr -> 오버로딩 연산자 이용 
	delete[]tempstr;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int main()
{
	std::string str1 = "I like";
	std::string str2 = "string class";
	std::string str3 = str1 + str2;
	//이 문장을 통해 +operator overloading이 되었다는것을 알 수 있다. 

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	//<<또한 overloding 되었다는 것을 알 수 있다. 

	str1 += str2;

	if (str1 == str3)
	{
		std::cout << "동일 문자열!" << std::endl;
	}
	else
	{
		std::cout << "동일 하지 않은 문자열!" << std::endl;
	}

	std::string str4;
	std::cout << "문자열 입력: ";
	std::cin >> str4;
	std::cout << "입력한 문자열: " << str4 << std::endl;
	return 0;
}

