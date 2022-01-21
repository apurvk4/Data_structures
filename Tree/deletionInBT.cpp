#include<iostream>
#include "binaryTree.hpp"
binaryTree<int> * replacementRight(binaryTree<int> * prev,binaryTree<int> * root){
    if(root==NULL){
        return NULL;
    }
    if(root->right_==NULL){
        if(prev !=NULL){
            prev->right_=NULL;
        }
        return root;
    }
    binaryTree<int> * p=replacementRight(root,root->right_);
    return p;
}
binaryTree<int> * replacement(binaryTree<int> * prev,binaryTree<int> * root){
    if(root==NULL){
        return NULL;
    }
    if(root->left_==NULL){
        if(prev!=NULL){
            prev->left_=NULL;
        }
        return root;
    }
    binaryTree<int> * p=replacement(root,root->left_);
    return p;
}
void find_key(int key,binaryTree<int> * prev,binaryTree<int> * root,int ** flag){
    if(root==NULL){return;}
    if(root->data_==key){
        *(*flag)=1;
        if(prev !=NULL && prev->left_==root){
            binaryTree<int> * l=replacement(NULL,root);
            if(l==NULL){
                binaryTree<int> * r=replacementRight(NULL,root);
                if(r==NULL){
                    prev->left_=NULL;
                    free(root);
                }else{
                    if(r==root){
                        prev->left_=NULL;
                        free(r);
                    }else{
                        root->data_=r->data_;
                        free(r);
                    }
                }
            }else{
                if(l==root){
                    prev->left_=NULL;
                    free(l);
                }else{
                    root->data_=l->data_;
                    free(l);
                }
            }
        }else if(prev !=NULL && prev->right_ ==root){
            binaryTree<int> * l=replacement(NULL,root);
            if(l==NULL){
                binaryTree<int> * r=replacementRight(NULL,root);
                if(r==NULL){
                    prev->left_=NULL;
                    free(root);
                }else{
                    if(r==root){
                        prev->right_=NULL;
                        free(r);
                    }else{
                        root->data_=r->data_;
                        free(r);
                    }
                }
            }else{
                if(l==root){
                    prev->right_=NULL;
                    free(l);
                }else{
                    root->data_=l->data_;
                    free(l);
                }
            }
        }
        return;
    }
    find_key(key,root,root->left_,flag);
    if(*(*flag)==1){return;}
    find_key(key,root,root->right_,flag);
}
void deletionBT(binaryTree<int>* root, int key)
{
    if(root==nullptr){return;}
    if(root->data_ == key){
        if(root->left_== NULL && root->right_==NULL){
            free(root);
            root=NULL;
            return;
        }else if(root->left_ !=NULL && root->right_ ==NULL){
            binaryTree<int> * p=root;
            root=root->left_;
            free(p);
            return;
        }else if(root->right_ !=NULL && root->left_ ==NULL){
            binaryTree<int> * p=root;
            root=root->right_;
            free(p);
            return;
        }else{
            binaryTree<int> * l=replacement(NULL,root);
            root->data_=l->data_;
            free(l);
        }
    }
    int f=0;
    int *p=&f;
    find_key(key,NULL,root,&p);
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