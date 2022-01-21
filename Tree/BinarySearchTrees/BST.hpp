#pragma once
#include<initializer_list>
#include<unordered_map>
#include<vector>
template<typename T>
class BST{
    public:
        void insert(const T & val){
            if(this->root==nullptr){
                root=new node(val);
                size_++;
                return;
            }
            typename BST::node * temp=root;
            typename BST::node * prev=nullptr;
            int flag=-1;
            while(temp !=nullptr){
                if(temp->_data < val){
                    prev=temp;
                    temp=temp->right;
                    flag=1;
                }else if(temp->_data > val){
                    prev=temp;
                    temp=temp->left;
                    flag=0;
                }else{
                    return;
                }
            }
            if(flag==0){
                prev->left=new node(val);
                size_++;
            }
            if(flag==1){
                prev->right=new node(val);
                size_++;
            }
        }
        BST():root{nullptr},size_{0}{
        }
        BST(T val):size_{0}{
            root=new node(val);
            size_++;
        }
        BST(std::initializer_list<T> l):size_{0},root{nullptr}{
            for (auto vals : l){
                insert(vals);
            }
        }
        const T floor(const T & key) {
            if(this->root==nullptr){
               throw std::invalid_argument("root is null");
            }
            typename BST::node * temp=this->root;
            typename BST::node * prev=nullptr;
            while(temp !=nullptr){
                if(key==temp->_data){return key;}
                if(key>temp->_data){
                    prev=temp;
                    temp=temp->right;
                    continue;
                }
                if(key<temp->_data){
                    temp=temp->left;
                }
            }
            if(prev==nullptr){
               throw std::logic_error("not found!");
            }
            return prev->_data;
        }
        const T ceil(const T & key) {
            if(this->root==nullptr){
               throw std::invalid_argument("root is null");
            }
            typename BST::node * temp=this->root;
            typename BST::node * prev=nullptr;
            while(temp !=nullptr){
                if(key==temp->_data){return key;}
                if(key>temp->_data){
                    temp=temp->right;
                    continue;
                }
                if(key<temp->_data){
                    prev=temp;
                    temp=temp->left;
                }
            }
            if(prev==nullptr){
               throw std::logic_error("not found!");
            }
            return prev->_data;
        }
        void remove(const T & val){
            if(root==nullptr){
                return;
            }
            if(root->left==nullptr && root->right==nullptr ){
                if(root->_data==val){
                    delete root;
                    root=nullptr;
                    size_--;
                }
                return;
            }
            typename BST::node * temp=root;
            typename BST::node * prev=nullptr;
            int flag=-1;
            while(temp !=nullptr){
                if(val>temp->_data){
                    prev=temp;
                    temp=temp->right;
                    flag=0;
                }else if(val<temp->_data){
                    prev=temp;
                    temp=temp->left;
                    flag=1;
                }else{
                    if(temp->left !=nullptr && temp->right==nullptr){
                        if(flag==1){
                            prev->left=temp->left;
                            delete temp;
                            size_--;
                        }else if(flag==0){
                            prev->right=temp->left;
                            delete temp;
                            size_--;
                        }else{
                            root=root->left;
                            delete temp;
                            size_--;
                        }
                    }else if(temp->right !=nullptr && temp->left==nullptr){
                        if(flag==1){
                            prev->left=temp->right;
                            delete temp;
                            size_;
                        }else if(flag==0){
                            prev->right=temp->right;
                            delete temp;
                            size_--;
                        }else{
                            root=root->right;
                            delete temp;
                            size_--;
                        }   
                    }else if(temp->left==nullptr && temp->right == nullptr){
                        delete temp;
                        if(flag==1){
                            prev->left=nullptr;
                        }else if(flag==0){
                            prev->right=nullptr;
                        }else{
                            root=nullptr;
                        }
                    }else{
                      typename BST::node * temp1=temp->left;
                      prev=temp;
                      bool f=false;
                      while(temp1->right !=nullptr){
                          f=true;
                          prev=temp1;
                          temp1=temp1->right;
                      }
                      if(!f){
                            temp->_data=temp1->_data;
                            prev->left=temp1->left;
                            delete temp1; 
                            size_--;
                      }else{
                        prev->right=nullptr;
                        temp->_data=temp1->_data;
                        delete temp1;
                        size_--;
                      }
                    }
                    break;
                }
            }
        }
        // std::vector<int> verticalSum(){
        //     std::unordered_map<int,int> mp;
        //     int minKey=INT32_MAX;
        //     int maxKey=INT32_MIN;
        //     traverse(this->root,0,mp,minKey,maxKey);
        //     std::vector<int> out;
        //     for(int i=minKey;i<=maxKey;i++){
        //         if(mp.find(i) != mp.end()){
        //             out.push_back(mp[i]);
        //         }
        //     }
        //     return out;
        // }
        void clear(){
            distroy(this->root);
            this->root=nullptr;
        }
        bool find(const T & val){
            if(root==nullptr){return false;}
            typename BST::node * temp=root;
            while(temp !=nullptr){
                if(temp->_data==val){return true;}
                if(val>temp->_data){
                    temp=temp->right;
                }
                if(val<temp->_data){
                    temp=temp->left;
                }
            }
            return false;
        }
        ~BST(){
            distroy(this->root);
        }
        const unsigned int size(){
            return size_;
        }
    private:
        unsigned int size_=0;
        struct node{
            T _data;
            node * left;
            node * right;
            node(T val):_data{val},left{nullptr},right{nullptr}{
            }
        };
        void traverse(typename BST::node * root,int k,std::unordered_map<int,int> & mp,int & mink,int & maxk){
            if(root==nullptr){return;}
            if(mp.find(k)==mp.end()){
                mp[k]=root->_data;
            }else{
                mp[k]=mp[k]+root->_data;
            }
            mink=std::min(mink,k);
            maxk=std::max(maxk,k);
            if(root->left !=nullptr){
                traverse(root->left,k-1,mp,mink,maxk);
            }
            if(root->right !=nullptr){
                traverse(root->right,k+1,mp,mink,maxk);
            }
            
        }
        typename BST<T>::node* root;
        void distroy(typename BST::node * n){
            if(n==nullptr){return;}
            if(n->left==nullptr && n->right==nullptr){
                delete n;
                size_--;
                return;
            }
            if(n->left !=nullptr){
                distroy(n->left);
                n->left=nullptr;
            }
            if(n->right !=nullptr){
                distroy(n->right);
                n->right=nullptr;
            }
            if(n->left==nullptr && n->right==nullptr){
                delete n;
                size_--;
            } 
        }
};