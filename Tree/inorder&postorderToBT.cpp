#include<iostream>
#include "binaryTree.hpp"
#include<unordered_map>
enum side{left,right};
int findMax(int arr[],int start,int end,std::unordered_map<int,int> & mp1){
    int res=INT32_MIN;
    for(int i=start;i<=end;i++){
        res=std::max(res,mp1[arr[i]]);
    }
    return res;
}
void insert(int arr[],int start,int end,side t,std::unordered_map<int,int> & mp,std::unordered_map<int,int> & mp1, binaryTree<int> * root,int post[]){
    if(t==left){
        if(start==end){
            root->insert_left(post[findMax(arr,start,end,mp1)]);
        }else if(end>start){
            root->insert_left(post[findMax(arr,start,end,mp1)]);
            int index=mp[root->left_->data_];
            insert(arr,start,index-1,left,mp,mp1,root->left_,post);
            insert(arr,index+1,end,right,mp,mp1,root->left_,post);
        }
    }else if(t==right){
        if(start==end){
            root->insert_right(post[findMax(arr,start,end,mp1)]);
        }else if(end> start){
            root->insert_right(post[findMax(arr,start,end,mp1)]);
            int index=mp[root->right_->data_];
            insert(arr,start,index-1,left,mp,mp1,root->right_,post);
            insert(arr,index+1,end,right,mp,mp1,root->right_,post);
        }
    }
}
binaryTree<int> * ToBT(int in[],int n,int post[],int m){
    std::unordered_map<int,int> mp,mp1;
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
        mp1[post[i]]=i;
    }
    binaryTree<int> * root=new binaryTree<int>(post[m-1]);
    int index=mp[post[m-1]];
    if(index==0){
        insert(in,index+1,n,right,mp,mp1,root,post);
    }else if(index==n-1){
        insert(in,0,index-1,left,mp,mp1,root,post);
    }else{
        insert(in,0,index-1,left,mp,mp1,root,post);
        insert(in,index+1,n-1,right,mp,mp1,root,post);
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
void PostOrderTraverse(binaryTree<int> ** node){
    if((*node)->left_==nullptr && (*node)->right_==nullptr){
        std::cout<<(*node)->data_<<" ";
        return;
    }else if((*node)->left_==nullptr){
        PostOrderTraverse(&((*node)->right_));
        std::cout<<(*node)->data_<<" ";
        return;
    }else if((*node)->right_==nullptr){
        PostOrderTraverse(&((*node)->left_));
        std::cout<<(*node)->data_<<" ";
        return;
    }else{
        PostOrderTraverse(&((*node)->left_));
        PostOrderTraverse(&((*node)->right_));
        std::cout<<(*node)->data_<<" ";
        return;
    }
}
int main(){
    int in[]={11,345,33,34,9,55,12,17,56,3456,90,45};
    int post[]={11,33,345,55,9,34,17,3456,56,45,90,12};
    // int in[]={20,10,40,30,50};
    // int pre[]={10,20,30,40,50};
    binaryTree<int> * root=ToBT(in,12,post,12);
    inorderTraverse(&root);
    std::cout<<"\n";
    std::cout<<"=========================================="<<"\n";
    PostOrderTraverse(&root);
    std::cout<<"\n";
    return 0;
}