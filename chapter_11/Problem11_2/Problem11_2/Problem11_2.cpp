// Problem11_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* title, char* isbn, int value) : price(value)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	//기초 클래스 복사 생성자
	Book(const Book& ref): price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	//기초 클래스 대입 연산자
	Book& operator=(const Book& ref)
	{
		delete []title;
		delete []isbn;
		
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}

	void ShowBookInfo()
	{
		std::cout << "제목: "<<title << std::endl;
		std::cout << "ISBN: "<<isbn << std::endl;
		std::cout << "가격: "<<price << std::endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class Ebook : public Book
{
private:
	char* DRMKey;
public:
	Ebook(char* title, char* isbn, int value, char* key) :Book(title, isbn, value)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}
	void ShowEbookInfo()
	{
		ShowBookInfo();
		std::cout << "인증키: " << DRMKey << std::endl << std::endl;
	}
	//유도 클래스 복사 생성자
	Ebook(const Ebook& ref) : Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	//유도 클래스 대입 연산자 
	Ebook& operator=(const Ebook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	~Ebook()
	{
		delete[]DRMKey;
	}
};

int main()
{
	Ebook B1 ((char*)"this is first book", (char*)"00000-1111-33333", 5600,(char*)"fsqwewqqdqwd");
	B1.ShowEbookInfo();

	Ebook B2((char*)"this is Second book", (char*)"00000-22222-33333", 6500, (char*)"aaaaaaa");

	//대입 연산자 확인 
	B2 = B1;
	B2.ShowEbookInfo();

	//복사 생성자 확인 
	Ebook B3 = B1;
	B3.ShowEbookInfo();

	return EXIT_SUCCESS;
}