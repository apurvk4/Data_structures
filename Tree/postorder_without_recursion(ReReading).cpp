#include<iostream>
#include "binaryTree.hpp"
#include "../stack/stack.h"
 void PostOrderTraverse(binaryTree<int> ** node){
   auto curr=*node;
   stack<binaryTree<int> *> st;
   while(curr !=nullptr || !st.empty()){
       if(curr !=nullptr){
           st.push(curr);
           curr=curr->left_;
       }else{
           auto temp=st.top()->right_;
           if(temp==nullptr){
               temp=st.top();
               st.pop();
               std::cout<<temp->data_<<" ";
               while (!st.empty() && temp==st.top()->right_){
                    temp=st.top();
                    st.pop();
                    std::cout<<temp->data_<<" ";
               }
           }else{
               curr=temp;
           }
       }
   }
}
int main(){
    auto head=new binaryTree<int>(12);
     head->insert_left(34);
     head->insert_right(90);
     head->left_->insert_left(345);
     head->left_->insert_right(9);
     head->right_->insert_left(56);
     head->right_->insert_right(45);
     head->right_->left_->insert_left(17);
     head->right_->left_->insert_right(3456);
     head->left_->left_->insert_left(11);
     head->left_->left_->insert_right(33);
     head->left_->right_->insert_right(55);
     PostOrderTraverse(&head);
     std::cout<<"\n";
     return 0;
}