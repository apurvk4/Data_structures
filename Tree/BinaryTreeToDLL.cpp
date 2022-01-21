#include<iostream>
#include "binaryTree.hpp"
//left=prev
//right=next
void ToDLL(binaryTree<int> * node,binaryTree<int> *& prev){
   if(node->left_ ==nullptr && node->right_==nullptr){
       if(prev !=nullptr){
           prev->right_=node;
       }
       node->left_=prev;
       prev=node;
       return;
   }
   if(node->left_ !=nullptr){
        ToDLL(node->left_,prev);
    }
    if(prev !=nullptr){
        prev->right_=node;
        node->left_=prev;
        prev=prev->right_;
    }else{
        prev=node;
    }
   if(node->right_ !=nullptr){
        ToDLL(node->right_,prev);
   }
}
void treeToDLL(binaryTree<int> ** head){
     if(*head==nullptr){
         return;
     }
     binaryTree<int> * p=nullptr;
     ToDLL(*head,p);
     binaryTree<int> * temp=*head;
     while(temp->left_ !=nullptr){
         temp=temp->left_;
     }
     *head=temp;
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
    treeToDLL(&head);
    auto temp=head;
     while(temp!=nullptr){
        std::cout<<temp->data_<<" ";
        temp=temp->right_;
    }
    std::cout<<"\n";
     return 0;
}