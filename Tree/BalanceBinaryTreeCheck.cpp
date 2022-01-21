#include<iostream>
#include "binaryTree.hpp"
#include<memory>
int checkBalancedBinaryTree(binaryTree<int> * node){
    if(node==nullptr){
        return 0;
    }
    int lh=checkBalancedBinaryTree(node->left_);
    if(lh==-1){return -1;}
    int rh=checkBalancedBinaryTree(node->right_);
    if(rh==-1){return -1;}
    if(abs(lh-rh)>1){return -1;}
    return std::max(lh,rh)+1;
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
    // head.get()->insert_left(4);
    // head->insert_right(20);
    // head->right_->insert_left(13);
    // head->left_->insert_right(70);
    // head.get()->left_->insert_left(77);
    // head->left_->right_->insert_left(45);
    // head->left_->right_->insert_right(55);
     if(checkBalancedBinaryTree(head)>=0){
        std::cout<<std::boolalpha<<true<<"\n";
     }else{
        std::cout<<std::boolalpha<<false<<"\n";        
     }
     return 0;
}