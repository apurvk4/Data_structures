#include "queue.h"
#include <iostream>
#include<string>
int main(){
    queue<int> q{200,400,500,600,700};
    q.push(2);
    q.push(235);
    q.push(345);
    q.push(12);
    q.push(234);
    int count=0;
    q.reverse();
    std::cout<<q.back()<<" "<<q.empty()<<" "<<q.front()<<" "<<q.size()<<"\n";
    while(!q.empty()){
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<"\n";
    return 0;
}