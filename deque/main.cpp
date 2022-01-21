#include<iostream>
#include "deque1.hpp"

int main(){
    deque<int> dq;
    dq.push_front(231);
    for(int i=0;i<4;i++){
        dq.push_front(i);
    }
    dq.push_front(34);
    dq.pop_back();
    std::cout<<dq.front()<<"\n"<<dq.back()<<"\n";
    return 0;
}