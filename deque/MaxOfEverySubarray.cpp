#include<iostream>
#include "deque.hpp"
#include<vector>
std::vector<int> MaxArray(int arr[],int n,int k){
   std::vector<int> out;
   deque<int> dq;
   int count=0;
   for(int i=0;i<n;i++){
      if(count==k){
          if(dq.front()==arr[i-k]){
              if(arr[i]<dq.front()){
                  i=i-k;
                  out.push_back(dq.front());
                  dq.clear();
                  count=0;
                  continue;
              }else{                                     
                  out.push_back(dq.front());
                  dq.pop_back();
                  dq.push_back(arr[i]);
                  continue;
              }
           }else{
               out.push_back(dq.front());
               count--;
           }
       }
      if(dq.empty()){
          dq.push_back(arr[i]);
          count++;
      }else if(arr[i]>dq.front()){
          dq.pop_back();
          dq.push_back(arr[i]);
          count++;
      }else{
          count++;
      }
    }
    out.push_back(dq.front());
   return out;
}
int main(){
    int arr[]={20,5,3,8,6,15};
    std::vector<int> out=MaxArray(arr,6,4);
    for(auto element : out){
        std::cout<<element<<" ";
    }
    std::cout<<"\n";
    return 0;
}