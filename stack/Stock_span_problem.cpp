#include "stack.h"
#include<iostream>
#include<vector>
std::vector<int> stock_span(std::vector<int> & stock){
  stack<int> st;
  std::vector<int> out;
     out.push_back(1);
     for(int i=0;i<(int)(stock.size());i++){
       if(st.empty()){
           st.push(i);
       }else if(stock[st.top()]>stock[i]){
           out.push_back(i-st.top());
           st.push(i);
       }else{
          while(!st.empty()){
              if(stock[st.top()]>stock[i]){
                  out.push_back(i-st.top());
                  st.push(i);
                  break;
              }
              st.pop();
          }
          if(st.empty()){
              out.push_back(i+1);
              st.push(i);
          }
       }

    }
   return out;
}
int main(){
    std::vector<int> v{15,13,12,14,16,8,6,4,10,30};
    std::vector<int> out=stock_span(v);
    for(auto num : out){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";
    return 0;
}