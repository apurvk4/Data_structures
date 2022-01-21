#pragma once
#include "../dll_base.h"
#include<initializer_list>
template<typename T>
class deque:public Node<T>{
    public:
     deque()=default;
     deque(std::initializer_list<T>);
     ~deque()=default;
     void push_back(T &);
     void push_back(T &&);
     void pop_back();
     void pop_front();
     void reverse();
     void push_front(T & );
     void push_front(T &&);
     const unsigned int size();
     bool empty();
     const T & front();
     const T & back();
     void clear();
    private:
     unsigned int size_=0;
     T & get_data()=delete;
};
template<typename T>
deque<T>::deque(std::initializer_list<T> l):size_{0}{
  for(auto data: l){
      this->push_back(data);
  }
}
template<typename T>
void deque<T>::push_back(T & val){
    Node<T>::push_back(val);
    size_++;
}
template<typename T>
void deque<T>::push_back(T && val){
    Node<T>::push_back(val);
    size_++;
}
template<typename T>
void deque<T>::push_front(T & val){
    Node<T>::push_front(val);
    size_++;
}
template<typename T>
void deque<T>::push_front(T && val){
    Node<T>::push_front(val);
    size_++;
}
template<typename T>
void deque<T>::pop_back(){
    Node<T>::pop_back();
    size_--;
}
template<typename T>
void deque<T>::pop_front(){
    Node<T>::pop_front();
    size_--;
}
template<typename T>
void deque<T>::reverse(){
    Node<T>::reverse();
}
template<typename T>
bool deque<T>::empty(){
    return size_==0;
}
template<typename T>
const unsigned int deque<T>::size(){
    return size_;
}
template<typename T>
const T & deque<T>::front(){
    return this->head_->get_data();
}
template<typename T>
const T & deque<T>::back(){
    return this->tail_->get_data();
}
template<typename T>
void deque<T>::clear(){
    while (!this->empty()){
        this->pop_back();
    }
}