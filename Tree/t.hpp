#pragma once
#include<unordered_set>
template<typename T>
class binaryTree{
   public:
    node * root;
    
    binaryTree(T val){
        root=new node(val);
        s.insert(root);
    }
    ~binaryTree(){
    
    }
    void insert_left(const T & data){
        node * p=new node(data);
        s.insert(p);
        
    }
    void insert_right(const T & data){

    }
    struct node{
        public:
            T data_;
            node * left_;
            node * right_;
            node(T val):data_{val},left_{nullptr},right_{nullptr}{
            }
            void insert_left(const T & data){

            }
            void insert_right(const T & data){

            }
    };

   private:
    std::unordered_set<node*> s;
};