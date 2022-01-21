#include "stack.h"
#include<string>
#include<iostream>
bool BalancedParenthesis(std::string & s){
    stack<char> st;
     for(int i=0;i<(int)(s.size());i++){
       if(s[i]=='(' || s[i]=='{' || s[i]=='['){
           st.push(s[i]);
       }
       if(s[i]==')' || s[i]=='}' || s[i]==']'){
           if(st.empty()){return false;}
           if(st.top()=='{' && s[i]=='}'){
             st.pop();
             continue;
           }
           if(st.top()=='[' && s[i]==']'){
              st.pop();
              continue;
           }
           if(st.top()=='(' && s[i]==')'){
               st.pop();
               continue;
           }
           return false;
       }
    }
    if(!st.empty()){
      return false;
    }
    return true;
}
int main(){
    std::string s;
    std::cout<<"enter string : ";
    std::cin>>s;
    std::cout<<std::boolalpha<<BalancedParenthesis(s)<<"\n";
    return 0;
}