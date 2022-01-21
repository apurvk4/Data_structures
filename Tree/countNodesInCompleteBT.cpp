#include<iostream>
#include "binaryTree.hpp"
int countNodes(binaryTree<int> * node){
    auto ptr=node;
    int count=0;
    int prev=0;
    while(ptr !=nullptr){
        if(ptr->left_ !=nullptr){
            if(ptr->left_->left_ !=nullptr){
                if(ptr->right_ !=nullptr){
                    if(ptr->right_->right_ ==nullptr){
                        // only one extra full level and one partially filled level.
                        if(prev==0){prev=2;count+=prev;node=node->left_;continue;}
                        count+=prev*prev;
                        prev=prev*prev;
                        break;
                    }else{
                        if(prev==0){prev=2;count+=prev;node=node->left_;continue;}
                        count+=prev*prev;
                        prev=prev*prev;
                        node=node->left_;
                        continue;
                    }
                }else{
                    // not possible in case of balanced BT.
                }
            }else if(ptr->right_ !=nullptr && ptr->right_->right_ ==nullptr){
                    // only one more level(full).
                    if(prev==0){prev=2;count+=prev;node=node->left_;break;}
                    count+=prev*prev;
                    prev=prev*prev;
                    break;
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

    return 0;
}