/*
Given an array of distinct integers,
find the NextGreater(position-wise closest and on the right side) 
of every array elements.
*/
#include<iostream>
#include "stack.h"
#include<vector>
std::vector<int> NextGreater(std::vector<int> & in){
      std::vector<int> out((int)(in.size()));
      out[(int)(in.size())-1]=-1;
      stack<int> st;
      for(int i=(int)(in.size())-1;i>=0;i--){
          if(st.empty()){
              st.push(i);
          }else if(in[st.top()]>in[i]){
              out[i]=st.top();
              st.push(i);
          }else{
              while(!st.empty()){
                  if(in[st.top()]>in[i]){
                      out[i]=st.top();
                      st.push(i);
                      break;
                  }
                  st.pop();
              }
              if(st.empty()){
                  out[i]=-1;
                  st.push(i);
              }
          }
      }
     return out;
}
int main(){
    std::vector<int> v{25,20,15,10};
    std::vector<int> out=NextGreater(v);
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