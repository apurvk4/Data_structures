#include<iostream>
#include "binaryTree.hpp"
bool childrenSumProperty(binaryTree<int> * node){
    if(node !=nullptr){
      if(node->left_==nullptr && node->right_==nullptr){
          return true;
       }else if(node->left_ !=nullptr && node->right_ !=nullptr){
         if(node->data_!=node->left_->data_+node->right_->data_){
             return false;
         }
      }else if (node->left_ !=nullptr && node->right_==nullptr){
         if(node->data_!=node->left_->data_){
             return false;
         }
      }else if(node->left_==nullptr && node->right_ !=nullptr){
         if(node->data_!=node->right_->data_){
             return false;
         }
      }
      return (childrenSumProperty(node->left_) && childrenSumProperty(node->right_));
    }else{
      return true;
    }
}

int main(){
     auto head=new binaryTree<int>(20);
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
    // head->insert_left(8);//
    // head->insert_right(12);
    // head->left_->insert_left(3);
    // head->left_->insert_right(5);//
    // head->insert_right(30);
    // head->right_->insert_right(70);
    // head->right_->right_->insert_right(80);
    std::cout<<std::boolalpha<<childrenSumProperty(nullptr);
    std::cout<<"\n";
    return 0;
}