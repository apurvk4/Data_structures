#include<iostream>
#include "binaryTree.hpp"
#include<iostream>
#include "binaryTree.hpp"
int height(binaryTree<int> * node,int & di){
   if(node==nullptr){
       return 0;
   }
   int a=height(node->left_,di);
   int b=height(node->right_,di);
   di=std::max(di,a+b+1);
   return std::max(a,b)+1;
}

int diameter(binaryTree<int> * node){
    if(node==nullptr){
        return 0;
    }
    int di=INT32_MIN;
    height(node,di);
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