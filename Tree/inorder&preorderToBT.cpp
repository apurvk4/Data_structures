#include<iostream>
#include "binaryTree.hpp"
#include<unordered_map>
enum side{left,right};
void insert(int arr[],int start,int end,side t,std::unordered_map<int,int> & mp,binaryTree<int> * root,int pre[],int & m){
    if(t==left){
        if(start==end){
            root->insert_left(pre[++m]);
        }else if(end>start){
            root->insert_left(pre[++m]);
            int index=mp[root->left_->data_];
            insert(arr,start,index-1,left,mp,root->left_,pre,m);
            insert(arr,index+1,end,right,mp,root->left_,pre,m);
        }
    }else if(t==right){
        if(start==end){
            root->insert_right(pre[++m]);
        }else if(end> start){
            root->insert_right(pre[++m]);
            int index=mp[root->right_->data_];
            insert(arr,start,index-1,left,mp,root->right_,pre,m);
            insert(arr,index+1,end,right,mp,root->right_,pre,m);
        }
    }
}
binaryTree<int> * ToBT(int in[],int n,int pre[],int m){
    std::unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    binaryTree<int> * root=new binaryTree<int>(pre[0]);
    int index=mp[pre[0]];
    int j=0;
    if(index==0){
        insert(in,index+1,n,right,mp,root,pre,j);
    }else if(index==n-1){
        insert(in,0,index-1,left,mp,root,pre,j);
    }else{
        insert(in,0,index-1,left,mp,root,pre,j);
        insert(in,index+1,n-1,right,mp,root,pre,j);
    }
    return root;
}
void inorderTraverse(binaryTree<int> ** node){
    if((*node)->left_==nullptr && (*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        return;
    }else if((*node)->left_==nullptr){
        std::cout<<(*node)->data_<<" ";
        inorderTraverse(&((*node)->right_));
        return;
    }else if((*node)->right_==nullptr){
        inorderTraverse(&((*node)->left_));
        std::cout<<(*node)->data_<<" ";
        return;
    }else{
        inorderTraverse(&((*node)->left_));
        std::cout<<(*node)->data_<<" ";
        inorderTraverse(&((*node)->right_));
        return;
    }
}
void PreOrderTraverse(binaryTree<int> ** node){
    if((*node)->left_==nullptr && (*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        return;
    }else if((*node)->left_==nullptr){
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->right_));
        return;
    }else if((*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->left_));
        return;
    }else{
        std::cout<<(*node)->data_<<" ";
        PreOrderTraverse(&((*node)->left_));
        PreOrderTraverse(&((*node)->right_));
        return;
    }
}
int main(){
    int in[]={11,345,33,34,9,55,12,17,56,3456,90,45};
    int pre[]={12,34,345,11,33,9,55,90,56,17,3456,45};
    // int in[]={20,10,40,30,50};
    // int pre[]={10,20,30,40,50};
    binaryTree<int> * root=ToBT(in,12,pre,12);
    inorderTraverse(&root);
    std::cout<<"\n";
    std::cout<<"=========================================="<<"\n";
    PreOrderTraverse(&root);
    std::cout<<"\n";
    return 0;
}