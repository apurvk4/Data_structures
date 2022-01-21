#include<iostream>
#include "stack.h"
#include<string>
#include<sstream>
#include<math.h>
/*
(^ =1) (+ =2) (* =3) (/ =4) (- = 5) else -1
*/
int find_operator(char ch){
    if(ch=='^'){return 1;}
    if(ch=='+'){return 2;}
    if(ch=='*'){return 3;}
    if(ch=='/'){return 4;}
    if(ch=='-'){return 5;}
    return -1;
}
int  operate(int n1,int n2,int type){
    switch (type)
    {
    case 1:
        return (int)(pow(n1,n2));
    case 2:
        return n1+n2;
    case 3:
       return n1*n2;
    case 4:
       return n1/n2;
    case 5:
       return n1-n2;
    default:
        break;
    }
}
int evaluate_postfix(std::string & s){
  stack<int> st;
  for( char ch : s){
      if(find_operator(ch)==-1){
          std::stringstream str;
          str<<ch;
          int num;
          str>>num;
          st.push(num);
      }else{
          int n1=st.top();
          st.pop();
          int n2=st.top();
          st.pop();
          int out=operate(n2,n1,find_operator(ch));
          st.push(out);
      }
  }
  return st.top();
}
int main(){
    std::string str{"105+606/*8-"};
    std::cout<<evaluate_postfix(str)<<"\n";
    return 0;
}