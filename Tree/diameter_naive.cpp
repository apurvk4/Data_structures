#include<iostream>
#include "binaryTree.hpp"
int height(binaryTree<int> * node){
   if(node==nullptr){
       return 0;
   }
   return std::max(height(node->left_),height(node->right_))+1;
}
void dim(binaryTree<int> * node,int & di){
    if(node==nullptr){
        return;
    }
    di=std::max(di,height(node->left_)+height(node->right_)+1);
    dim(node->left_,di);
    dim(node->right_,di);
}
int diameter(binaryTree<int> * node){
    if(node==nullptr){
        return 0;
    }
    int di=INT32_MIN;
    dim(node,di);
    return di;
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
     std::cout<<diameter(head)<<"\n";
    return 0;
}