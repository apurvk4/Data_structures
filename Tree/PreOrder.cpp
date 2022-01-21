#include<iostream>
#include "binaryTree.hpp"
void PreOrderTraverse(binaryTree<int> ** node){
    if((*node)->left_==nullptr && (*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        return;
    }else if((*node)->left_==nullptr){
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->right_));
        return;
    }else if((*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->left_));
        return;
    }else{
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->left_));
        PreOrderTraverse(&((*node)->right_));
        return;
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
     PreOrderTraverse(&head);
     std::cout<<"\n";
     return 0;
}