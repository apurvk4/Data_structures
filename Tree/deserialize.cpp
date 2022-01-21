#include<iostream>
#include "binaryTree.hpp"
#include<string>
#include "../queue/queue.h"
int strip(const std::string & str,char end){
    static int count=0;
    if(count>=str.size()){
        throw std::logic_error("no numbers remaining");
    }
    std::string out;
    for(;count<str.size();count++){
        if(str[count]==end){
           break;
        }
        out.push_back(str[count]);
    }
    if(out=="N"){
        count++;
        return INT32_MIN;
    }
    int x=std::stoi(out);
    count++;
    return x;
}
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
binaryTree<int> * deserialize(const std::string & tree){
      queue<binaryTree<int> *> q;
      binaryTree<int> * p=nullptr;
      try{
        int value=strip(tree,' ');
        if(value==INT32_MIN){return p;}
        p=new binaryTree<int>(value); 
      }catch(std::logic_error & e){return p;}
      q.push(p);
      while(true){
        auto curr=q.front();
        q.pop();
        try{
            int value=strip(tree,' ');
            if(value==INT32_MIN){
             goto other;      
            }
            curr->insert_left(value);
            q.push(curr->left_);
        }catch(std::logic_error & e){break;}
        other:
        try{
            int value=strip(tree,' ');
            if(value==INT32_MIN){
                continue;
            }
            curr->insert_right(value);
            q.push(curr->right_);
        }catch(std::logic_error & e){break;}
      }
      return p;
}
void BFS(binaryTree<int> **node){
     queue<binaryTree<int> *> q;
     q.push(*node);
     q.push(nullptr);
     while(q.size()>1){
         auto ptr=q.front();
         if(ptr==nullptr){
             std::cout<<"\n";
             q.push(nullptr);
         }else{
             std::cout<<ptr->data_<<" ";
         }
         q.pop();
         if(ptr !=nullptr){
            if(ptr->left_ !=nullptr){
                q.push(ptr->left_);
            }
            if(ptr->right_ !=nullptr){
                q.push(ptr->right_);
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
     BFS(&head);
     std::cout<<"\n Before \n";

     std::string out=serialize(head);
     binaryTree<int> * p=deserialize(out);
      BFS(&p);
     std::cout<<"\n";
     return 0;
}