#include<iostream>
#include "binaryTree.hpp"
#include<string>
#include "../queue/queue.h"
std::string serialize(binaryTree<int> * node){
  queue<binaryTree<int> *> q;
  std::string str;
  q.push(node);
  while(!q.empty()){
      int count=q.size();
      for(int i=0;i<count;i++){
          auto curr=q.front();
          q.pop();
          if(curr==nullptr){str=str+"N ";continue;}
          std::string s1=std::to_string(curr->data_);
          str=str+s1+" ";
          q.push(curr->left_);
          q.push(curr->right_);
      }
      if(q.front()==nullptr){break;}
  }
  if(str[str.size()-1]==' '){str.pop_back();}
  return str;
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
     std::cout<<serialize(head)<<"\n";
     return 0;
}