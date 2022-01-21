#include<iostream>
#include "singly_linked-list.h"
// 1 2 3 4 5 6 7
void pairWiseSwap(linked_list<int> & l){
     bool flag=true;
  if(get_head(l) !=nullptr){
      auto ptr=get_head(l);
      while(get_next(get_next(ptr)) !=nullptr){
          auto p1=get_next(ptr);
          std::swap(get_value(ptr),get_value(p1));
          ptr=get_next(p1);
          if(ptr==get_tail(l)){
              flag=false;
              break;
          }
      }
      if(flag){
        std::swap(get_value(ptr),get_value(get_next(ptr)));   
      }
  }
}
int main(){
    linked_list<int> l(88);
    l.push_back(89);
    l.push_back(90);
    l.push_back(78);
    l.push_back(66);
    l.push_back(77);
    l.push_back(33);
    l.push_back(55);
    pairWiseSwap(l);
    for(auto it=l.begin();it !=l.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
    return 0;
}