//
// Created by 장현준 on 2022/11/27.
//

#ifndef OBSERVERPATTERN_PERSON_H
#define OBSERVERPATTERN_PERSON_H
#include "Observable.h"
class Person : public Observable<Person>
{
public:
    Person (int age) : Observable<Person>()
    {
        this->age = age;
    }
    int getAge(){return age;}
    void setAge(const int changedAge)
    {
        if(this->age == changedAge || changedAge < 0) return;
        auto old_can_vote = can_vote();

        this->age = changedAge;
        notify(*this,"age");

        if(old_can_vote != can_vote())
            notify(*this,"can_Vote");
    }
    bool can_vote() const
    {
        return age >= 16;
    }
private:
    int age;
};
#endif //OBSERVERPATTERN_PERSON_H
