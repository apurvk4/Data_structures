#include<iostream>
#include "singly_linked-list.h"
void deleteNode(linked_list<int> * Node){
  if(get_next(Node) !=nullptr){
      if(get_next(get_next(Node))!=nullptr){
          set_value(Node,get_value(get_next(Node)));
          auto n=get_next(Node);
          set_next(Node,get_next(n));
          delete n;
      }else{
          set_value(Node,get_value(get_next(Node)));
          auto n=get_next(Node);
          set_next(Node,nullptr);
          set_tail(Node);
      }
  }
}
int main(){
    linked_list<int> l(88);
    l.push_back(89);
    l.push_back(90);
    l.push_back(78);
    l.push_back(66);
    // DetectAndRemoveLoop(l);
    auto ptr=get_head(l);
    ptr=get_next(ptr);
    ptr=get_next(ptr);
    ptr=get_next(ptr);
    deleteNode(ptr);
    for(auto it=l.begin();it !=l.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
    return 0;
}