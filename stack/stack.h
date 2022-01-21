#pragma once
#include "../queue/queue.h"
#include<initializer_list>
template<typename T>
class stack:public queue<T>{
    public:
     stack()=default;
     stack(std::initializer_list<T>);
     ~stack()=default;
     T & top();
     void pop();
    private:
     T & front()=delete;
     T & back()=delete;
};
template<typename T>
T & stack<T>::top(){
    return queue<T>::back();
}
template<typename T>
void stack<T>::pop(){
    this->pop_front();
    this->size_-=1;
}
template<typename T>
stack<T>::stack(std::initializer_list<T> l):queue<T>(l){
}



