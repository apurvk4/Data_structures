#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
void BFS(binaryTree<int> **node){
     queue<binaryTree<int> *> q;
     q.push(*node);
     while(!q.empty()){
         auto ptr=q.front();
         std::cout<<ptr->data_<<" ";
         q.pop();
         if(ptr->left_ !=nullptr){
             q.push(ptr->left_);
         }
         if(ptr->right_ !=nullptr){
             q.push(ptr->right_);
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
     BFS(&head);
     std::cout<<"\n";
     return 0;
}