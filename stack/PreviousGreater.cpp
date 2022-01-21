/*
Given an array of distinct integers, 
find the closest (positive wise) greater on left of every element.
 If there is no greater element on left, then print -1
*/
#include<iostream>
#include "stack.h"
#include<vector>
std::vector<int> PreviousGreater(std::vector<int> in){
   stack<int> st;
   std::vector<int> out;
   out.push_back(-1);
   for(int i=0;i<(int)(in.size());i++){
       if(st.empty()){
           st.push(i);
       }else if(in[st.top()]>in[i]){
           out.push_back(st.top());
           st.push(i);
       }else{
           while (!st.empty()){
               if(in[st.top()]>in[i]){
                   out.push_back(st.top());
                   st.push(i);
                   break;
               }
               st.pop();
           }
           if(st.empty()){
               out.push_back(-1);
               st.push(i);
           }
       }
   }
   return out;
}
int main(){
    std::vector<int> v{12,10,8};
    std::vector<int> out=PreviousGreater(v);
    for(auto num : out){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
    for(auto num : out){
        if(num !=-1){
          std::cout<<v[num]<<" ";
        }else{
            std::cout<<num<<" ";
        }
    }
    std::cout<<"\n";
    return 0;
}