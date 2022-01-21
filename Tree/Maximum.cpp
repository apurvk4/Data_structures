#include<iostream>
#include "binaryTree.hpp"
void max(binaryTree<int> * node,int & mx){
      if(node !=nullptr){
          mx=std::max(mx,node->data_);
          max(node->left_,mx);
          max(node->right_,mx);
      }
}
int maximum(binaryTree<int> * root){
    if(root==nullptr){
        return INT32_MIN;
    }
    int mx=INT32_MIN;
    max(root,mx);
    return mx;
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
     std::cout<<maximum(head)<<"\n";
     return 0;
}