#include<iostream>
#include "../Tree/binaryTree.hpp"
#include<unordered_set>
bool check(binaryTree<int>* root,int l,int r){
    if(root==nullptr){return true;}
    if(root->data_ <= l || root->data_ >= r){return false;}
    bool a=check(root->left_,l,root->data_);
    if(!a){return false;}
    bool b=check(root->right_,root->data_,r);
    if(!b){return false;}
    return true;
}
bool checkForBst(binaryTree<int> * root){
    return check(root,INT32_MIN,INT32_MAX);
}
int main(){
 std::unordered_set<binaryTree<int> *> s;
 binaryTree<int> * head=new binaryTree<int>(20);
 s.insert(head);
 head->insert_left(8);
 s.insert(head->left_);
 head->insert_right(30);
 s.insert(head->right_);
 head->right_->insert_left(18);
 s.insert(head->right_->left_);
 head->right_->insert_right(35);
 s.insert(head->right_->right_);
 std::cout<<std::boolalpha<<checkForBst(head)<<"\n";
 for(auto val: s){
     delete val;
 }
}