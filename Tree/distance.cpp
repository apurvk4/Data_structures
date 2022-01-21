#include<iostream>
#include "binaryTree.hpp"
int distance(binaryTree<int> * node,int n1,int & count){
    if(node==nullptr){return 0;}
    if(node->data_==n1){return count;}
    int a=distance(node->left_,n1,++count);
    if(a==-1 || a==0){count--;}
    if(a>0){return count;}
    int b=distance(node->right_,n1,++count);
    if(b==-1 || b==0){count--;}
    if(b>0){return count;}
    return -1;
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
     int count=0;
     std::cout<<distance(head,45,count)<<"\n";
    return 0;
}