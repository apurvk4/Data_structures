#include<iostream>
#include "stack.h"
#include<vector>
std::vector<int> NextGreater(std::vector<int> & in){
      std::vector<int> out((int)(in.size()));
      out[(int)(in.size())-1]=-1;
      Stack<int> st;
      for(int i=(int)(in.size())-1;i>=0;i--){
          if(st.empty()){
              st.push(i);
          }else if(in[st.top()]<in[i]){
              out[i]=st.top();
              st.push(i);
          }else{
              while(!st.empty()){
                  if(in[st.top()]<in[i]){
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
std::vector<int> PreviousGreater(std::vector<int> in){
   Stack<int> st;
   std::vector<int> out;
   out.push_back(-1);
   for(int i=0;i<(int)(in.size());i++){
       if(st.empty()){
           st.push(i);
       }else if(in[st.top()]<in[i]){
           out.push_back(st.top());
           st.push(i);
       }else{
           while (!st.empty()){
               if(in[st.top()]<in[i]){
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
int LargestRectangularArea(std::vector<int> & in){
    std::vector<int> nxt=NextGreater(in);
    std::vector<int> pre=PreviousGreater(in);
    int MaxArea=0;
    for(int i=0;i<(int)(in.size());i++){
        int p=pre[i];
        int n=nxt[i];
        if(p !=-1){
            if(n !=-1){
                int res=(n-p+1)*in[i];
                if(res>MaxArea){
                    MaxArea=res;
                }
            }else{
              int res=(i-p+1)*in[i];
              if(res>MaxArea){
                  MaxArea=res;
              }
            }
        }else{
            if(n !=-1){
                int res=(n-i+1)*in[i];
                if(res>MaxArea){
                    MaxArea=res;
                }
            }else{
                int res=in[i];
                if(res>MaxArea){
                    MaxArea=res;
                }
            }
        }   
    }
    return MaxArea;
}
int main(){
    std::vector<int> arr{6,2,5,4,1,5,6};
    int m=LargestRectangularArea(arr);
    std::cout<<m<<"\n";
    getchar();
    return 0;
}