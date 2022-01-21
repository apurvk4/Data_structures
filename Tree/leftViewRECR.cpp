#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
int currLevel=0;
void leftView(binaryTree<int> * node,int level){
  if(node==nullptr){
      return;
  }
  if(currLevel<level){
      std::cout<<node->data_<<" ";
      currLevel=level;
  }
  leftView(node->left_,level+1);
  leftView(node->right_,level+1);
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
    leftView(head,1);
    std::cout<<"\n";
    return 0;
}