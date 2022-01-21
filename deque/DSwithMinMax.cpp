#include<iostream>
#include "deque.hpp"
template<typename T>
class ds{
    public:
     void insertMin(T & val){
         dq.push_front(val);
     }
     void insertMin(T && val){
         dq.push_front(val);
     }
     void insertMax(T & val){
         dq.push_back(val);
     }
     void insertMax(T && val){
         dq.push_back(val);
     }
     const T & getMin(){
         return dq.front();
     } 
     const T & getMax(){
         return dq.back();
     }
     void extractMin(){
         dq.pop_front();
     }
     void extractMax(){
         dq.pop_back();
     }
    private:
     deque<T> dq;
};
int main(){
    ds<int> d;
    d.insertMin(5);
    d.insertMax(10);
    d.insertMin(3);
    d.insertMax(15);
    d.insertMin(2);
    std::cout<<d.getMin()<<" "<<d.getMax()<<"\n";
    d.insertMin(1);
    std::cout<<d.getMin()<<"\n";
    d.insertMax(20);
    std::cout<<d.getMax()<<"\n";
    return 0;
}