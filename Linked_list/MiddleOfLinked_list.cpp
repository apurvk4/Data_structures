#include "singly_linked-list.h"
#include<iostream>
void printmiddle(linked_list<int> & l){
  if(l.empty()){
      return;
  }
    auto slow=l.begin();
   for(auto fast=l.begin();fast !=l.end();){
      fast++;
      if(fast!=nullptr){
          fast++;
          slow++;
      }else{
          break;
      }
  }
  std::cout<<*slow<<"\n";
}
int main(){
    linked_list<int> l;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        l.push_back(num);
    }
    printmiddle(l);
    return 0;
}