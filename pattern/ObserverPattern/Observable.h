//
// Created by 장현준 on 2022/11/27.
//

#ifndef OBSERVERPATTERN_OBSERVABLE_H
#define OBSERVERPATTERN_OBSERVABLE_H
#include "Observer.h"
template<typename T> class Observer;
template <typename  T> class Observable
{
public:
    Observable(){}
    void notify(T& source, const std::string& name)
    {
        std::vector<Observer<T>*> observersCopy;
        {
            std::lock_guard<std::mutex> guard(mtx);
            observersCopy = observers;
        }

        for(auto obs : observers)
        {
            if(obs)
                obs->field_changed(source, name);
        }

        //이상황 에서 unScribe를 들어 가려고 하면 가능 할 것이다.
        observers.erase(remove(observers.begin(),observers.end(),
                        nullptr),observers.end());
    }
    void subScribe(Observer<T>* observer)
    {
        std::lock_guard<std::mutex> guard(mtx);
        observers.push_back(observer);
    }
    void unScribe(Observer<T>* observer)
    {
        std::lock_guard<std::mutex> guard(mtx);
        auto it = std::find(observers.begin(), observers.end(),observer);
        if(it != observers.end())
            *it = nullptr;
        //typename std::vector<Observer<T>*>::iterator iter;
        //iter = std::find(observers.begin(), observers.end(),observer);
       //if(iter != observers.end())
        //{
          //  observers.erase(iter);
        //}
    }
private:
    std::vector<Observer<T>*> observers;
    //std::vector는 스레드 안정적 적이지 않다.
    //따라서 subScribe() 와 unScribe()가 동시에 호출 된다면 의도 하지않은 결과가 발생 할 수 있다.
    //왜냐면 두함수 모두 vector를 수정 하려고 들기 때문이다.
    std::mutex mtx;
};

#endif //OBSERVERPATTERN_OBSERVABLE_H
