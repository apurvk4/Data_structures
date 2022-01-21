#pragma once
template<typename T>
class binaryTree{
    public:
     binaryTree(T val):data_{val},left_{nullptr},right_{nullptr}{
     }
     void insert_left(T val){
         binaryTree<T> * ptr= new binaryTree<T>(val);
         this->left_=ptr;
     }
     void insert_right(T val){
         binaryTree<T> * ptr= new binaryTree<T>(val);
         this->right_=ptr;
     }
     ~binaryTree(){
           destroy(this);   
     }
      T data_;
      binaryTree<T> * left_;
      binaryTree<T> * right_;
      void clear(){
         destroy(this);
      }
      private:
       void destroy(binaryTree<T> *node){
              if(node !=nullptr){
                  destroy(node->left_);
                  destroy(node->right_);
                  delete node;
              }
       }
};