#include<iostream>
#include "singly_linked-list.h"
void merge(linked_list<int> & fst,linked_list<int> & scnd){
    linked_list<int> l;
    auto ptr1=get_head(fst);
    auto ptr2=get_head(scnd);
    while(ptr1 !=nullptr && ptr2 !=nullptr){
        if(get_value(ptr1)>get_value(ptr2)){
            l.push_back(get_value(ptr2));
            ptr2=get_next(ptr2);
        }else{
            l.push_back(get_value(ptr1));
            ptr1=get_next(ptr1);
        }
    }
    while(ptr1 !=nullptr){
        l.push_back(get_value(ptr1));
        ptr1=get_next(ptr1);
    }
    while(ptr2 !=nullptr){
        l.push_back(get_value(ptr2));
        ptr2=get_next(ptr2);
    }
    for(auto it=l.begin();it !=l.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}
int main(){
    linked_list<int> l,ll;
    int size;
    std::cout<<"enter size of 1st linked-list : ";
    std::cin>>size;
    while(size--){
        int num;
        std::cout<<"enter value : ";
        std::cin>>num;
        l.push_back(num);
    }
    std::cout<<"enter size of 2nd linked-list : ";
    std::cin>>size;
    while(size--){
        int num;
        std::cout<<"enter value : ";
        std::cin>>num;
        ll.push_back(num);
    }
    merge(l,ll);
    return 0; 
}