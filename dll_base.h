#pragma once
template<typename T>
class Node{
    public:
     T & get_data(){
       return this->data_;
     }
    protected:
      Node * head_=nullptr;
      Node * tail_=nullptr;
      void push_back(T &);
      void push_back(T &&);
      void pop_back();
      void pop_front();
      void reverse();
      void push_front(T & );
      void push_front(T &&);
      Node(T &);
      Node();
     ~Node();
      T data_;
      Node *  next_=nullptr;
      Node * prev_=nullptr;
};
template<typename T>
void Node<T>::push_back(T & val){
  if(this->head_==nullptr){
    Node * temp=new Node(val);
    this->head_=temp;
    this->tail_=temp;
  }else{
    Node * temp=new Node(val);
    this->tail_->next_=temp;
    temp->prev_=this->tail_;
    this->tail_=temp;
  }
}
template<typename T>
void Node<T>::push_back(T && val){
  if(this->head_==nullptr){
    Node * temp=new Node(val);
    this->head_=temp;
    this->tail_=temp;
  }else{
    Node * temp=new Node(val);
    this->tail_->next_=temp;
    temp->prev_=this->tail_;
    this->tail_=temp;
  }
}
template<typename T>
void Node<T>::pop_back(){
  if(head_ !=nullptr){
    if(head_->next_ ==nullptr){
      delete head_;
      head_=nullptr;
      tail_=nullptr;
    }else{
      Node * temp=tail_->prev_;
      temp->next_=nullptr;
      delete tail_;
      tail_=temp;
    } 
  }
}
template<typename T>
void Node<T>::pop_front(){
  if(head_ !=nullptr){
    if(head_->next_ ==nullptr){
      delete head_;
      head_=nullptr;
      tail_=nullptr;
    }else{
      Node * temp=head_->next_;
      temp->prev_=nullptr;
      delete head_;
      head_=temp;
    } 
  }
}
template<typename T>
Node<T>::Node():prev_{nullptr},next_{nullptr},head_{nullptr},tail_{nullptr}{  
}
template<typename T>
Node<T>::Node(T & val):data_{val},next_{nullptr},prev_{nullptr},head_{nullptr},tail_{nullptr}{
}
template<typename T>
Node<T>::~Node(){
  if(head_ !=nullptr){
    if(head_==tail_){
        delete head_;
        head_=nullptr;
        tail_=nullptr;
    }else{
          Node *n1,*n2;
          n1=head_;
          while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next_;
            delete n2;
          }
          head_=nullptr;
          tail_=nullptr;
    }
  }
}
template<typename T>
void Node<T>::push_front(T & val){
    if(head_==nullptr && tail_==nullptr){
        Node<T> *ptr =new Node<T>(val);
        head_=ptr;
        tail_=ptr;
        head_->next_=nullptr;
        head_->prev_=nullptr;
    }else{
        Node<T> *ptr =new Node<T>(val);
        ptr->next_=head_;
        head_->prev_=ptr;
        ptr->prev_=nullptr;
        head_=ptr;
    }
}
template<typename T>
void Node<T>::push_front(T && val){
    if(head_==nullptr && tail_==nullptr){
        Node<T> *ptr =new Node<T>(val);
        head_=ptr;
        tail_=ptr;
        head_->next_=nullptr;
        head_->prev_=nullptr;
    }else{
        Node<T> *ptr =new Node<T>(val);
        ptr->next_=head_;
        head_->prev_=ptr;
        ptr->prev_=nullptr;
        head_=ptr;
    }
}
template<typename T>
void Node<T>::reverse(){
    if(this->head_ != nullptr){
      Node<T> * temp;
      Node<T> * temp1=this->head_;
      while(temp1 !=nullptr){
        if(temp1==this->head_){
          temp=temp1;
          temp1=temp1->next_;
          temp->next_=nullptr;
          temp->prev_=temp1;
        }else{
          temp=temp1;
          temp1=temp1->next_;
          temp->next_=temp->prev_;
          temp->prev_=temp1;
        }
      }
      temp1=this->tail_;
      this->tail_=this->head_;
      this->head_=temp1;
    }
}