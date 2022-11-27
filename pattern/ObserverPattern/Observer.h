//
// Created by 장현준 on 2022/11/27.
//


#ifndef OBSERVERPATTERN_OBSERVER_H
#define OBSERVERPATTERN_OBSERVER_H
#include "Person.h"
#include <iostream>
template<typename T> class Observer
{
public:
    virtual void field_changed(T& Source,const std::string& field_name) = 0;
};
//제네릭한 일반적인 옵저버

//사람의 변화를 관찰하는 옵저버 제넥리한 클래스를 상속 해서 줄땐 자료형을 지정해서 준다.
class ConsolePersonObserver :  public Observer<Person>
{
public:
    virtual void field_changed(Person& source, const std::string& fieldName) override
    {
        std::cout << "Person's " << fieldName << " has changed to " << source.getAge() << "\n";
    }
};

class TrafficAdministaration : public Observer<Person>
{
public:
    void field_changed(Person& source, const std::string& field_name) override
    {
        if(field_name == "age")
        {
            if(source.getAge() < 17)
            {
                std::cout << "whoa there, you are not old enough to drive!\n";
            }
            else
            {
                std::cout << "We no longer care!\n";
                source.unScribe(this);
            }
        }
    }
};

#endif //OBSERVERPATTERN_OBSERVER_H
