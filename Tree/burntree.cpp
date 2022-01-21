#include<iostream>
#include "binaryTree.hpp"
#include "../stack/stack.h"
int height(binaryTree<int> * node,int n1){
    if(node !=nullptr && node->left_==nullptr && node->right_==nullptr ){
         return 1;
    }
    if(node==nullptr){
        return 0;
    }
    if(node->data_==n1){return 0;}
    return std::max(height(node->left_,n1),height(node->right_,n1))+1;
}
int distance(binaryTree<int> * node,int n1,int & count){
    if(node==nullptr){return 0;}
    if(node->data_==n1){return count;}
    int a=distance(node->left_,n1,++count);
    if(a==-1 || a==0){count--;}
    if(a>0){return count;}
    int b=distance(node->right_,n1,++count);
    if(b==-1 || b==0){count--;}
    if(b>0){return count;}
    return -1;
}
void ancestors(binaryTree<int> * node,stack<binaryTree<int>*> & anc,int n1,bool & flag){
    if(node==nullptr){return;}
    if(node->data_==n1){flag=true;return;}
    anc.push(node->left_);
    ancestors(node->left_,anc,n1,flag);
    if(!flag){anc.pop();}else{return;}
    anc.push(node->right_);
    ancestors(node->right_,anc,n1,flag);
    if(!flag){anc.pop();}else{return;}
}
int burn(binaryTree<int> * node,int n1){
    stack<binaryTree<int>*> anc;
    bool flag=false;
    ancestors(node,anc,n1,flag);
    if(!flag){return -1;}
    auto ptr=anc.top();
    int pop_count=0;
    int res=INT32_MIN;
    int count=0;
    anc.pop();
    pop_count++;
    while(!anc.empty()){
        distance(node,anc.top()->data_,count);
        int b=height(node,n1);
        std::cout<<b<<"\n";
        res=std::max(res,b+pop_count+count);
        count=0;
        anc.pop();
        pop_count++;
    }
    return res;
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
    //  head->left_->right_->insert_right(55);/////
    head->insert_left(20);
    // head->insert_right(30);
    head->left_->insert_left(30);
    // head->left_->insert_right(50);
    head->left_->left_->insert_left(40);
    head->left_->left_->insert_right(50);
     std::cout<<burn(head,50)<<"\n";
    return 0;
}