#include "stack.h"
#include<iostream>
#include<algorithm>
/*
  1. reverse the infix expression.
  2. find postfix expression of reversed infix expression.
  3. reverse the postfix expression and this will be our result.
*/
int find_operator(char ch){
    if(ch=='^'){return 0;}
    if(ch=='%'){return 1;}
    if(ch=='+'){return 2;}
    if(ch=='*'){return 3;}
    if(ch=='/'){return 4;}
    if(ch=='-'){return 5;}
    if(ch=='('){return 6;}
    if(ch=='{'){return 7;}
    if(ch=='['){return 8;}
    if(ch==')'){return 9;}
    if(ch=='}'){return 10;}
    if(ch==']'){return 11;}
    return -1;
}
int precedence(char pre,char nw){
    if(pre=='*' && (nw=='+'|| nw=='-')){
       return 1;
    }else if((pre=='+' || pre=='-') && (nw=='+'|| nw=='-')){
        return 0;
    }else if(pre=='('|| pre=='{' || pre=='['){     
        return -1;                              // ^ operator is to be added 
    }else if((pre=='*'|| pre=='/' || pre=='%') && (nw=='*' || nw=='/' || nw=='%')){
        return 2;
    }else if((pre=='+'|| pre=='-')&&(nw=='*'|| nw=='/' || nw=='%')){
        return 3;
    }else if(nw=='('|| nw=='{' || nw=='['){
        return -1;
    }
}
std::string infix_to_postfix(std::string & in){
  stack<char> op;
  std::string out;
  for (auto ch : in){
      if(find_operator(ch)==-1){
          out.push_back(ch);
      }else if(find_operator(ch)>=0 && find_operator(ch)<=8){
          if(op.empty()){
              op.push(ch);
          }else{
              int p=precedence(op.top(),ch);
              if(p==1 || p==0 || p==2){
                  while(!op.empty()){
                      out.push_back(op.top());
                      op.pop();
                    if(!op.empty()){
                        if(find_operator(op.top())>=6 && find_operator(op.top())<=8){
                             break;
                         }
                    }
                  }
                  op.push(ch);
              }
              if(p==-1){
                  op.push(ch);
              }
              if(p==3){
                  op.push(ch);
              }
          }
      }else if(find_operator(ch)>=9 && find_operator(ch)<=11){
          while(!op.empty()){
                if(find_operator(op.top())>=6 && find_operator(op.top())<=8){
                        op.pop();
                       break;
                 }
                out.push_back(op.top());
                op.pop();
          }
      }
  }
  while (!op.empty()){
      out.push_back(op.top());
      op.pop();
  }
  return out;
}
std::string toprefix(std::string in){
  int l=in.size();
  std::reverse(in.begin(),in.end());
  for(int i=0;i<l;i++){
    if(in[i]=='('){
      in[i]=')';
    }else if(in[i]==')'){
      in[i]='(';
    }else if(in[i]=='{'){
      in[i]='}';
    }else if(in[i]=='}'){
      in[i]='{';
    }else if(in[i]=='['){
      in[i]=']';
    }else if(in[i]==']'){
      in[i]='[';
    }
  }
  std::string pre=infix_to_postfix(in);
  std::reverse(pre.begin(),pre.end());
  return pre;
}

int main(){
    std::string in{"A+[(B+C)*D]/E"};
    std::string out=toprefix(in);
    std::cout<<out<<"\n";
    return 0;
}