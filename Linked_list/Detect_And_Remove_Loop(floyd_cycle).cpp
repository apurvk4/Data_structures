#include<iostream>
#include "singly_linked-list.h"
/*
floyd cycle claims that if there is a loop then if we move 
slow pointer to begining of list and move both fast & slow at same pace
then they will meet a start to loop.
*/
template<typename T>
void DetectAndRemoveLoop(linked_list<T> & obj){
  auto ptr=get_head(obj);
  auto slow=ptr;
  auto fast=ptr;
  bool flag=false;
  while(ptr !=nullptr && get_next(ptr) !=nullptr){
    slow=get_next(slow);
    fast=get_next(get_next(fast));
    if(slow==fast){
        flag=true;
        break;
    }
  }
  if(flag){
     slow=get_head(obj);
     while(get_next(slow) != get_next(fast)){
       slow=get_next(slow);
       fast=get_next(fast);
     }
   set_next(fast,nullptr);
  }
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
    DetectAndRemoveLoop(l);
    for(auto it=l.begin();it !=l.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
    return 0;
}