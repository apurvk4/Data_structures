#include<iostream>
#include "binaryTree.hpp"
#include<vector>
void recr(std::vector<int> & out,int count,int k,binaryTree<int> *node){
    if(count==k+1){
        if(node !=nullptr){
            out.push_back(node->data_);
        }
        return;
    }
    if(node !=nullptr){
        recr(out,count+1,k,node->left_);
        recr(out,count+1,k,node->right_);
    }
}
std::vector<int> NodesAtK(binaryTree<int> * node,int k){
  std::vector<int> out;
  if(node==nullptr){
      return out;
  }
  if(k==0){
      out.push_back(node->data_);
      return out;
  }
  recr(out,1,k,node);
  return out;
}
int main(){
     auto head=new binaryTree<int>(10);
    //  head->insert_left(34);
    //  head->insert_right(90);
    //  head->left_->insert_left(345);
    //  head->left_->insert_right(9);
    //  head->right_->insert_left(56);
    //  head->right_->insert_right(45);
    //  head->right_->left_->insert_left(17);
    //  head->right_->left_->insert_right(3456);
    //  head->left_->left_->insert_left(11);
    //  head->left_->left_->insert_right(33);
    //  head->left_->right_->insert_right(55);
    head->insert_left(20);
    head->insert_right(30);
    head->left_->insert_left(40);
    head->left_->insert_right(50);
    head->insert_right(30);
    head->right_->insert_right(70);
    head->right_->right_->insert_right(80);
     int k=2;
     std::vector<int> vec=NodesAtK(head,k);
     for(auto data : vec){
         std::cout<<data<<" ";
     }
     std::cout<<"\n";
     return 0;
}