#include<iostream>
#include "binaryTree.hpp"
#include "../stack/stack.h"
void inorderTraverse(binaryTree<int> ** node){
    stack<binaryTree<int> *> st;
    binaryTree<int> * curr=*node;
    while(curr !=nullptr || !st.empty()){
         while(curr !=nullptr){
             st.push(curr);
             curr=curr->left_;
         }
         curr=st.top();
         std::cout<<curr->data_<<"\n";
         curr=curr->right_;
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
     inorderTraverse(&head);
     std::cout<<"\n";
     return 0;
}