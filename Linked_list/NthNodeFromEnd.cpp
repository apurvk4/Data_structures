#include "singly_linked-list.h"
#include<iostream>
void NthNodeFromEnd(linked_list<int> & l,int n){
   if(l.empty()){return;}
   auto fast=l.begin();
   bool flag=false;
   for(int i=0;i<n;i++){
       if(fast !=nullptr){
          fast++;
       }else{
           flag=true;
           break;
       }
   }
   if(flag){
       return;
   }
   auto slow=l.begin();
   while(fast !=l.end()){
       fast++;
       slow++;
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
    NthNodeFromEnd(l,0);
    return 0;
}