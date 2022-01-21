#pragma once
#include<array>
template<typename T>
class stack{
    public:
     stack();
     stack(int);
     ~stack()=default;
     T & top();
     void push(T &&);
     void push(T &);
     void pop();
     bool empty();
    private:
     int size_;
     int end_=-1;
     std::array<T,size_> arr;
};
template<typename T>
stack<T>::stack():size_{200},end_{-1}{
}
template<typename T>
stack<T>::stack(int sz):size_{sz},end_{-1}{
}
template<typename T>
T & stack<T>::top(){
    return arr[end_];
}
template<typename T>
void stack<T>::push(T & val){
  if(end_>=size_-1){
    throw std::invalid_argument("stack overflow error");
  }
  arr[++end_]=val;
}
template<typename T>
void stack<T>::push(T && val){
  if(end_>=size_-1){
    throw std::invalid_argument("stack overflow error");
  }
  arr[++end_]=val;
}
template<typename T>
void stack<T>::pop(){
    if(end==-1){
        throw std::invalid_argument("stack underflow error");
    }
    end_--;
}
template<typename T>
bool stack<T>::empty(){
  return (end_==-1);
}