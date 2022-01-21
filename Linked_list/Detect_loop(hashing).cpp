#include<iostream>
#include "singly_linked-list.h"
#include<unordered_set>
template<typename T>
bool DetectLoop(linked_list<T> & obj){
  std::unordered_set<linked_list<T> *> s;
  linked_list<T> * ptr=get_head(obj);
  while(ptr !=nullptr){
   if(s.find(ptr) ==s.end()){
       s.insert(ptr);
       ptr=get_next(ptr);
   }else{
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