#include<iostream>
#include "binaryTree.hpp"
#include "../queue/queue.h"
#include<vector>
std::vector<int> NodesAtK(binaryTree<int> * node,int k){
    std::vector<int> out;
    if(node==nullptr){
        return out;
    }
    if(k==0){
        out.push_back(node->data_);
        return out;
    }
    int count=0;
    queue<binaryTree<int> *> q;
    q.push(node);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
           auto ptr=q.front();
           q.pop();
           if(ptr->left_ !=nullptr){
               q.push(ptr->left_);
           }
           if(ptr->right_ !=nullptr){
               q.push(ptr->right_);
           }
        }
        count++;
        if(count==k){
           while(!q.empty()){
               out.push_back(q.front()->data_);
               q.pop();
           }     
        }
    }
    return out;
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
     int k=3;
     std::vector<int> vec=NodesAtK(head,k);
     for(auto data : vec){
         std::cout<<data<<" ";
     }
     std::cout<<"\n";
     return 0;
}