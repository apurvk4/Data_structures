#include<iostream>
#include "binaryTree.hpp"
void size(binaryTree<int> * node,int & count){
    if(node !=nullptr){
        count++;
        size(node->left_,count);
        size(node->right_,count);
    }
}
int SizeofTree(binaryTree<int> * root){
    if(root==nullptr){
       return 0;
    }
    int count=0;
    size(root,count);
    return count;
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
     std::cout<<SizeofTree(head);
     std::cout<<"\n";
     return 0;
}