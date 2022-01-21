#include<iostream>
#include "singly_linked-list.h"
template<typename T>
bool DetectLoop(linked_list<T> & obj){
  auto ptr=get_head(obj);
  auto slow=ptr;
  auto fast=ptr;
  while(ptr !=nullptr && get_next(ptr) !=nullptr){
    slow=get_next(slow);
    fast=get_next(get_next(fast));
    if(slow==fast){
        return true;
    }
  }
  return false;
}
int main(){
    linked_list<int> l;
    l.push_back(89);
    l.push_back(90);
    l.push_back(78);
    l.push_back(66);
    auto head=get_head(l);
    auto tail=get_tail(l);
    set_next(tail,head);
    std::cout<<std::boolalpha<<DetectLoop<int>(l)<<"\n";
    return 0;
}