#pragma once
template<typename T>
 class linked_list
{
public:
     T &  front();
    const T & cfront();
    T & back();
    const T & cback(); 
    void push_back(T);
    void pop_back();
    void push_front(T);
    bool empty();
    void pop_front();
    linked_list(T);
    void clear();
    void reverse();
    void remove(T);
    // void ReverseInGroups(int);
    friend linked_list<T> * get_head(linked_list<T> & obj){
        return obj.head_;
    }
    friend linked_list<T> * get_tail(linked_list<T> & obj){
       return obj.tail_;
    }
    friend linked_list<T> * get_next(linked_list<T> * ptr){
          return ptr->next_;
    }
    friend void set_next(linked_list<T> * curr,linked_list<T> * nxt){
        curr->next_=nxt;
    }
    friend T & get_value(linked_list<T> *ptr){
           return ptr->value_;
    }
    friend void set_value(linked_list<T> * ptr,T val){
        ptr->value_=val;
    }
    friend void set_tail(linked_list<T> * ptr){
       ptr->tail_=ptr;
    }
    linked_list()=default;
    ~linked_list();
     class iterator{
         private:
           linked_list<T> * ptr_;
         public:
           iterator(linked_list<T> * ptr):ptr_{ptr}{
           }
           iterator operator++(int){
              ptr_=ptr_->next_;
              return *this;
           }
           iterator operator+=(int t){
              while(t>0){
                  ptr_=ptr_->next_;
                  t--;
              }
              return *this;
           }
           void swap(iterator rhs){
               T temp=this->ptr_->value_;
               this->ptr_->value_=rhs.ptr_->value_;
               rhs.ptr_->value_=temp;
           }
           iterator operator++(){
              ptr_=ptr_->next_;
              return *this;
           }
           const T & operator*(){
               return this->ptr_->value_;
           }
           bool operator==(const iterator & rhs){
               if(this->ptr_==rhs.ptr_){
                   return true;
               }else{
                   return false;
               }
           }
           bool operator !=(const iterator & rhs){
               if(this->ptr_!=rhs.ptr_){
                   return true;
               }else{
                   return false;
               }
           }
           linked_list<T>* operator->(){
               return this->ptr_;
           }
     };
     iterator begin(){
        return iterator(head_);
     }
     iterator end(){
        return iterator(tail_->next_);
    }
private:
    T value_=0;
    linked_list* next_=nullptr;
    linked_list* head_=nullptr;
    linked_list* tail_=nullptr;
};
template<typename T>
T & linked_list<T>::front(){
    return head_->value_;
}
template<typename T>
const T & linked_list<T>::cfront(){
    return head_->value_;
}
template<typename T>
T & linked_list<T>::back(){
    return tail_->value_;
}
template<typename T>
const T & linked_list<T>::cback(){
    return tail_->value_;
}
template<typename T>
linked_list<T>::~linked_list(){
    if(head_==tail_){
        delete head_;
        head_=nullptr;
        tail_=nullptr;
    }else{
        linked_list *n1,*n2;
        n1=head_;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next_;
            delete n2;
        }
    }
}
template<typename T>
bool linked_list<T>::empty(){
    if(head_==nullptr){
        return true;
    }else{
        return false;
    }
}
template<typename T>
void linked_list<T>::clear(){
  if(head_ !=nullptr && tail_ !=nullptr){
    if(head_==tail_){
        delete head_;
        head_=nullptr;
        tail_=nullptr;
    }else{
        linked_list *n1,*n2;
        n1=head_;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next_;
            delete n2;
        }
    }
  }
}
template<typename T>
void linked_list<T>::reverse(){
    if(head_ !=nullptr && tail_ !=nullptr){
        if(head_ != tail_){
          linked_list * n=nullptr;
          linked_list *n1=head_;
          linked_list *n2=head_->next_;
          n1->next_=nullptr;
          while(n2 !=nullptr){
              n=n1;
              n1=n2;
              n2=n2->next_;
              n1->next_=n;
          }
          n=head_;
          head_=tail_;
          tail_=n;
        }
    }
}
template<typename T>
void linked_list<T>::remove(T val){
    if(head_ !=nullptr && tail_ !=nullptr){
        if(head_==tail_){
            if(head_->value_==val){
                delete head_;
                head_=nullptr;
                tail_=nullptr;
            }
        }else if(head_->value_==val){
             linked_list * n=head_;
             head_=head_->next_;
             delete n;
        }else{
            linked_list * temp;
            temp=head_;
            while(temp->next_->value_!=val && temp->next_ !=tail_){
              temp=temp->next_;
            }
            if(temp->next_->value_==val ){
                if(temp->next_==tail_){
                    tail_=temp;
                    temp=temp->next_;
                    delete temp;
                    tail_->next_=nullptr;
                }else{
                    linked_list *n2=temp->next_->next_;
                    linked_list *n1=temp->next_;
                     temp->next_=n2;
                     n1->next_=nullptr;
                     delete n1;
                }
            }
        }
    }
}
template<typename T>
linked_list<T>::linked_list(T val)
{
  linked_list* n=new linked_list();
  n->value_=val;
     head_=n;
     head_->next_=nullptr;
     tail_=head_;
}
template<typename T>
void linked_list<T>::push_back(T val){
    if(head_ !=nullptr && tail_ !=nullptr){
               linked_list *n=new linked_list();
               n->value_=val;
               n->next_=nullptr;
               tail_->next_=n;
               tail_=n;
    }else{
        linked_list * n=new linked_list();
        n->value_=val;
        head_=n;
        head_->next_=nullptr;
        tail_= head_;
    }
}
template<typename T>
void linked_list<T>::pop_back(){
    if(head_ !=nullptr && tail_ !=nullptr){
       if(head_==tail_){
           delete head_;
           head_=nullptr;
           tail_=nullptr;
        }else{
           linked_list * temp;
           temp=head_;
           while(temp->next_ !=tail_){
              temp=temp->next_;
            }
            delete tail_;
            temp->next_=nullptr;
            tail_=temp;
        }
    }
}
template<typename T>
void linked_list<T>::push_front(T val){
    if(this->head_==nullptr){
       linked_list *n=new linked_list();
       n->value_=val;
       n->next_=nullptr;
       this->head_=n;
       this->tail_=n;
    }else{
        linked_list *n=new linked_list();
        n->value_=val;
        n->next_=head_;
        head_=n;
    }
}
template<typename T>
void linked_list<T>::pop_front(){
    if(head_ !=nullptr && tail_ !=nullptr){
        if(head_==tail_){
          delete head_;
          head_=nullptr;
          tail_=nullptr;
        }else{
          linked_list * n=head_;
          head_=head_->next_;
          delete n;
        }
    }
}



