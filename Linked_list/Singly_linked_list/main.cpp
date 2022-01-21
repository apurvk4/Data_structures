#include<iostream>
#include "singly_linked-list.h"
int main(){
    linked_list<int> l;
    l.push_back(23);
    l.push_back(90);
    l.push_back(89);
    for(auto it=l.begin();it !=l.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
    return 0; 
}