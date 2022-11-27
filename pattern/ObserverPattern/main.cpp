#include <iostream>
#include <string>
#include <vector>
#include "Observer.h"
#include "Person.h"

int main()
{
    /*Person p(20);
    ConsolePersonObserver cpo;
    p.subScribe(&cpo);
    p.setAge(21);
    p.unSubScribe(&cpo);
    p.setAge(22);*/


    Person p{10};
    TrafficAdministaration trafficObs;
    p.subScribe(&trafficObs);
    p.setAge(16);
    p.setAge(17);
    p.setAge(21);


    return 0;
}
