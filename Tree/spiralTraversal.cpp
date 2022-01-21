#include<iostream>
#include<deque>
#include "binaryTree.hpp"
enum side{left,right};
void spirallyTraverse(binaryTree<int> * node){
    std::deque<binaryTree<int> *> dq;
    int n=0;
    side s;
    dq.push_back(node);
    while(!dq.empty()){
      if(n%2==0){
          s=left;
          n++;
      }else{
          s=right;
          n++;
      }
      int count=dq.size();
      for(int i=0;i<count;i++){
          if(s==left){
             auto curr=dq.front();
             dq.pop_front();
             std::cout<<curr->data_<<" ";
             if(curr->left_ !=nullptr){
                 dq.push_back(curr->left_);
             }
             if(curr->right_ !=nullptr){
                 dq.push_back(curr->right_);
             }
          }else if(s==right){
              auto curr=dq.back();
              std::cout<<curr->data_<<" ";
              dq.pop_back();
              if(curr->right_ !=nullptr){
                  dq.push_front(curr->right_);
              }
              if(curr->left_ !=nullptr){
                 dq.push_front(curr->left_);
              }
          }
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
     spirallyTraverse(head);
     return 0;
}