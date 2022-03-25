#include <iostream>
#include <cstring>

using namespace std;

class Printer{
private:
    char str[100];
public:
    void SetString(char temp[]);
    void ShowString();
};

void Printer::SetString(char temp[]) {
   strcpy(str,temp);
}

void Printer::ShowString() {
    cout << str << endl;
}

int main() {

    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();


    return 0;
}
