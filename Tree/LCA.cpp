#include<iostream>
#include "binaryTree.hpp"
#include "../stack/stack.h"
void find(stack<binaryTree<int>*> & st,int n,binaryTree<int> * node,bool & flag){
     if(node==nullptr){return;}
     if(node->data_==n){
         flag=true;
         return;
     }
     st.push(node->left_);
     find(st,n,node->left_,flag);
     if(flag){
        return;
     }else{
         st.pop();
     }
     st.push(node->right_);
     find(st,n,node->right_,flag);
     if(flag){
        return;
     }else{
         st.pop();
     }
}
binaryTree<int> * LCA(binaryTree<int> * node,int n1,int n2){
    if(node==nullptr){return nullptr;}
    stack<binaryTree<int>*> st1,st2;
    st1.push(node);
    st2.push(node);
    bool flag=false;
    find(st1,n1,node,flag);
    if(!flag){return nullptr;}
    flag=false;
    find(st2,n2,node,flag);
    if(!flag){return nullptr;}
    flag=false;
    while(!st1.empty() && !st2.empty()){
        if(st1.top()==st2.top()){
            return st1.top();
        }
        if((st1.size()==1 && st2.size()>1)||(st2.size()==1 && st1.size()>1)){
            break;
        }
        st1.pop();
        st2.pop();
    }
    if(!flag){
        if(st1.size()==1 && st2.size()>1){
            while(!st2.empty()){
                if(st2.top()==st1.top()){
                    flag=true;
                    break;
                }
                st2.pop();
            }
        }else if(st2.size()==1 && st1.size()>1){
             while(!st1.empty()){
                 if(st2.top()==st1.top()){
                     flag=true;
                     break;
                 }
                st1.pop();
             }
        }
    }
    if(!flag){
       return nullptr;
    }
       if(st1.size()==1){
           return st1.top();
       }
    return st2.top();
}
int main(){
    auto head=new binaryTree<int>(10);
    head->insert_left(20);
    head->insert_right(30);
    head->right_->insert_left(40);
    head->right_->insert_right(50);
    head->right_->left_->insert_left(60);
    head->right_->right_->insert_left(70);
    head->right_->right_->insert_right(80);
    auto ptr=LCA(head,90,90);
    if(ptr !=nullptr){
        std::cout<<ptr->data_<<"\n";
    }else{
        std::cout<<"404 error not found !"<<"\n";
    }
}