#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
int height(binaryTree<int> * node){
    queue<binaryTree<int> *> q;
    q.push(node);
    int height=0;
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            auto ptr=q.front();
            q.pop();
            if(ptr->left_ !=nullptr){
                q.push(ptr->left_);
            }
            if(ptr->right_ !=nullptr){
                q.push(ptr->right_);
            }
        }
        height++;
    }
    return height;
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
     std::cout<<height(head)<<"\n";
     return 0;
}