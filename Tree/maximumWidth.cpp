#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
int maxWidth(binaryTree<int> * head){
    if(head==nullptr){
        return 0;
    }
    queue<binaryTree<int> *> q;
    q.push(head);
    int width=1;
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            auto curr=q.front();
            q.pop();
            if(curr->left_ !=nullptr){
                q.push(curr->left_);
            }
            if(curr->right_ !=nullptr){
                q.push(curr->right_);
            }
        }
        if(q.size()>width){
            width=q.size();
        }
    }
    return width;
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
     std::cout<<maxWidth(head)<<"\n";
     return 0;
}