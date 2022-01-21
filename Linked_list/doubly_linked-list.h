#pragma once
#include<stdexcept>
template<typename T>
class doubly_linked_list{
    public:
      const T & cfront();
      T & front();
      const T & cback();
      T & back();
      doubly_linked_list()=default;
      doubly_linked_list(T);
      void push_back(T);
      void push_front(T);
      void pop_front();
      void pop_back();
      bool empty();
      void clear();
      void insert_after(doubly_linked_list *,T);
      void insert_after(T,T);
      void insert_before(doubly_linked_list *,T);
      void insert_before(T,T);
      void erase(doubly_linked_list *);
      void erase(T);
      void reverse();
      friend doubly_linked_list<T> * get_head(doubly_linked_list<T> & );
      friend doubly_linked_list<T> * get_next(doubly_linked_list<T> & );
      friend const T & get_value(doubly_linked_list<T>*);
      ~doubly_linked_list();
      class iterator{
         private:
           doubly_linked_list<T> * ptr_;
         public:
           iterator(doubly_linked_list<T> * ptr):ptr_{ptr}{
           }
           iterator operator++(int){
              ptr_=ptr_->next_;
              return *this;
           }
           iterator operator++(){
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
           iterator operator--(int){
               ptr_=ptr_->prev_;
               return *this;
           }
           iterator operator-=(int t){
               while(t>0){
                  ptr_=ptr_->prev_;
                  t--;
              }
              return *this;
           }
           void swap(iterator rhs){
               T temp= this->ptr_->value_;
               this->ptr_->value_=rhs.ptr_->value_;
               rhs.ptr_->value_=temp;
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
           doubly_linked_list<T>* operator->(){
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
      T value_;
      doubly_linked_list *next_=nullptr;
      doubly_linked_list *prev_=nullptr;
      doubly_linked_list* head_=nullptr;
      doubly_linked_list * tail_=nullptr;
};
 /*
   returns read/write reference to the value_ stored in head_ pointer.
   throws an instance of std::logic_error in case head_ pointer is null.
*/
template<typename T>
T & doubly_linked_list<T>::front(){
   if(head_==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return head_->value_;
}
/*
    returns const reference to the value_ stored in head_ pointer.
    throws an instance of std::logic_error in case head_ pointer is null.
      */
template<typename T>
const T & doubly_linked_list<T>::cfront(){
    if(head_==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return head_->value_;
}
/*
   returns read/write reference to the value_ stored in tail_ pointer.
   throws an instance of std::logic_error in case head_ pointer is null.
*/
template<typename T>
T & doubly_linked_list<T>::back(){
    if(tail_==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return tail_->value_;
}
/*
    returns const reference to the value_ stored in tail_ pointer.
    throws an instance of std::logic_error in case head_ pointer is null.
*/
template<typename T>
const T & doubly_linked_list<T>::cback(){
    if(tail_==nullptr){throw std::logic_error("dereferencing a null pointer");}
    return tail_->value_;
}
/*
  one args constructor
*/
template<typename T>
doubly_linked_list<T>::doubly_linked_list(T val){
    doubly_linked_list *n= new doubly_linked_list<T>();
    n->value_=val;
    if(head_==nullptr && tail_==nullptr){
        head_=n;
        tail_=head_;
    }else{
        tail_->next_=n;
        n->prev_=tail_;
        tail_=n;
    }
}
/*
 Add the element to the end of doubly linked-list.
 @param__val : value_ to be inserted.
*/
template<typename T>
void doubly_linked_list<T>::push_back(T val){
   if(head_==nullptr && tail_==nullptr){
       doubly_linked_list * n= new doubly_linked_list<T>();
       n->value_=val;
       head_=n;
       tail_=n;
       head_->next_=nullptr;
       head_->prev_=nullptr;
   }else{
        doubly_linked_list * n= new doubly_linked_list<T>();
        n->value_=val;
        tail_->next_=n;
        n->prev_=tail_;
        n->next_=nullptr;
        tail_=n;
   }
}
/*
returns head pointer.
*/
template<typename T>
doubly_linked_list<T> * get_head(doubly_linked_list<T> & obj){
    return obj.head_;
}
/*
  returns next Node pointer to the provided Node pointer.
*/
template<typename T>
doubly_linked_list<T> * get_next(doubly_linked_list<T> * ptr){
    return ptr->next_;
}
/*
returns the value at any given Node pointer
*/
template<typename T>
doubly_linked_list<T> * get_value(doubly_linked_list<T> * ptr){
    return ptr->value_;
}
/*
removes element from end of doubly linked-list.
*/
template<typename T>
void doubly_linked_list<T>::pop_back(){
    if(head_ !=nullptr && tail_ !=nullptr){
       if(head_==tail_){
            delete head_;
            head_=nullptr;
            tail_=nullptr;
        }else{
            doubly_linked_list *ptr=tail_->prev_;
            tail_->prev_=nullptr;
            delete tail_;
            ptr->next_=nullptr;
            tail_=ptr;
        }
    }
}
/*
Adds element to the begining of doubly linked-list.
@param__val: value_ to be inserted.
*/
template<typename T>
void doubly_linked_list<T>::push_front(T val){
    if(head_==nullptr && tail_==nullptr){
        doubly_linked_list *ptr =new doubly_linked_list<T>();
        ptr->value_=val;
        head_=ptr;
        tail_=ptr;
        head_->next_=nullptr;
        head_->prev_=nullptr;
    }else{
        doubly_linked_list *ptr =new doubly_linked_list<T>();
        ptr->value_=val;
        ptr->next_=head_;
        head_->prev_=ptr;
        ptr->prev_=nullptr;
        head_=ptr;
    }
}
/*
removes the element from begining of doubly linked-list.
*/
template<typename T>
void doubly_linked_list<T>::pop_front(){
    if(head_ !=nullptr && tail_ !=nullptr){
       if(head_==tail_){
           delete head_;
           tail_=nullptr;
           head_=nullptr;
       }else{
           doubly_linked_list * ptr=head_->next_;
           head_->next_=nullptr;
           ptr->prev_=nullptr;
           delete head_;
           head_=ptr;
        }
    }
}
/*
return true if list is empty else returns false.
*/
template<typename T>
bool doubly_linked_list<T>::empty(){
    if(head_==nullptr && tail_==nullptr){
        return true;
    }else{
        return false;
    }
}
/*
clears the list.
*/
template<typename T>
void doubly_linked_list<T>::clear(){
    if(head_ !=nullptr && tail_ !=nullptr){
        if(head_==tail_){
            delete head_;
            tail_=nullptr;
            head_=nullptr;
        }else{
            doubly_linked_list * ptr=head_;
            doubly_linked_list * ptr1=ptr;
            while(ptr !=nullptr){
                ptr=ptr->next_;
                delete ptr1;
                ptr1=ptr;
            }
            head_=nullptr;
            tail_=nullptr;
        }
    }
}
/*
  simply erases a particular node if present.
@param__ptr: node pointer to be erased.
@return__: void 
throws std::invalid_argument if provided Node is not present.
*/
template<typename T>
void doubly_linked_list<T>::erase(doubly_linked_list<T> * ptr){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
    if(head_==tail_){
        if(head_==ptr){
            delete ptr;
            head_=nullptr;
            tail_=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }else if(ptr==tail_){
            tail_=tail_->prev_;
            delete ptr;
            ptr=nullptr;
    }else if(ptr==head_){
            head_=head_->next_;
            delete ptr;
            ptr=nullptr;
    }else{
        doubly_linked_list * n=head_;
        while(n != nullptr){
            if(n==ptr){
                break;
            }
            n=n->next_;
        }
        if(n==ptr){
            n=ptr->prev_;
            n->next_=ptr->next_;
            ptr->next_->prev_=n;
            delete ptr;
            ptr=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }
}
/*
simply erases a particular value if present and if same value is present 
multiple times it will erase the first one from begining.
@param__val: value to be erased
@return__: void 
throws std::logic_error if provided value is not present.
*/
template<typename T>
void doubly_linked_list<T>::erase(T val){
 if(head_ !=nullptr && tail_ !=nullptr){
    if(head_==tail_){
        if(head_->value_==val){
            delete head_;
            head_=nullptr;
            tail_=nullptr;
        }else{
            throw std::logic_error("not found");
        }
    }else if(head_->value_==val){
        doubly_linked_list* p=head_;
        head_=head_->next_;
        delete p;
        p=nullptr;
    }else if(tail_->value_==val){
        doubly_linked_list* p=tail_;
        tail_=tail_->prev_;
        delete p;
        p=nullptr;
    }else{
        doubly_linked_list * n=head_;
        doubly_linked_list * ptr;
        while(n != nullptr){
            if(n->value_==val){
                ptr=n;
                break;
            }
            n=n->next_;
        }
        if(n==nullptr){
            throw std::logic_error("not found");
        }else{
            n=ptr->prev_;
            n->next_=ptr->next_;
            ptr->next_->prev_=n;
            delete ptr;
        }
    }
 }else{
     std::logic_error("not found");
 }
}
/*
 It does what you think it does.
*/
template<typename T>
void doubly_linked_list<T>::reverse(){
    if(head_ !=nullptr && tail_ != nullptr){
        if(head_ !=tail_){
            doubly_linked_list * n=head_;
            doubly_linked_list * n1=nullptr;
            while(n != nullptr){
                n1=n->next_;
                n->next_=n->prev_;
                n->prev_=n1;
                n=n->prev_;
            }
            n=head_;
            head_=tail_;
            tail_=n;
        }
    }
}
/*
simple distructor . since we are using pointers internally so default constructor will cause lots of memory leaks.
*/
template<typename T>
doubly_linked_list<T>::~doubly_linked_list(){
    if(head_==tail_){
        delete head_;
        head_=nullptr;
        tail_=nullptr;
    }else{
        doubly_linked_list *n1,*n2;
        n1=head_;
        while(n1 !=nullptr ){
            n2=n1;
            n1=n1->next_;
            delete n2;
        }
    }
}
/*
It inserts a new node just after the provided node.
@param__ptr: node after which new node is to be inserted.
@param__val: value to be inserted in new node.
@return__: void
throws std::invalid_argument if provided_node is null.
throws std::logic_error if provided node is not present in the list.
*/
template<typename T>
void doubly_linked_list<T>::insert_after(doubly_linked_list<T> * ptr,T val){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
    if(head_ !=nullptr && tail_ !=nullptr){
          if(head_==tail_){
              doubly_linked_list * n=new doubly_linked_list<T>();
              n->value_=val;
              head_->next_=n;
              n->prev_=head_;
              tail_=n;
          }else if(tail_==ptr){
               push_back(val);
          }else{
              doubly_linked_list * n=head_;
              while(n != nullptr){
                  if(n==ptr){
                      break;
                    }
                   n=n->next_;
                }
              if(n==ptr){
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value_=val;
                  n1->next_=ptr->next_;
                  ptr->next_->prev_=n1;
                  ptr->next_=n1;
                  n1->prev_=ptr;
              }else{
                  throw std::logic_error("Provided Node not present");
              }
          }
    }else{
        push_back(val);
    }
}
/*
It inserts a new node just after the provided value , if same value is present at multiple 
locations then new node is inserted just after first occurance of that value.
@param__ p_val: provided value after which new node is to be inserted.
@param__ val: value to be inserted in new node.
@return__: void
throws std::logic_error if provided value is not present in the list.
*/
template<typename T>
void doubly_linked_list<T>::insert_after(T p_val,T val){
        if(head_ !=nullptr && tail_ !=nullptr){
          if(head_==tail_){
              if(head_->value_==p_val){
                 doubly_linked_list * n=new doubly_linked_list<T>();
                 n->value_=val;
                 head_->next_=n;
                 n->prev_=head_;
                 tail_=n;
              }else{
                  throw std::logic_error("Provided value not present");
              }
          }else if(tail_->value_==p_val){          
              push_back(val);
          }else{
              doubly_linked_list * n=head_;
              while(n != nullptr){
                  if(n->value_==p_val){
                      break;
                    }
                   n=n->next_;
                }
              if(n==nullptr){
                  throw std::logic_error("Provided value not present");
              }else{
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value_=val;
                  n1->next_=n->next_;
                  n->next_->prev_=n1;
                  n->next_=n1;
                  n1->prev_=n;
              }
          }
    }else{
        push_back(val);
    }
}
/*
It inserts a new node just before the provided node.
@param__ptr: node before which new node is to be inserted.
@param__val: value to be inserted in new node.
@return__: void
throws std::invalid_argument if provided_node is null.
throws std::logic_error if provided node is not present in the list.
*/
template<typename T>
void doubly_linked_list<T>::insert_before(doubly_linked_list<T>* ptr,T val){
    if(ptr==nullptr){throw std::invalid_argument("Invalid node");}
     if(head_ !=nullptr && tail_ !=nullptr){
           if(head_==tail_){
               if(head_==ptr){
                   push_front(val);
               }else{
                   throw std::logic_error("Provided Node not present");
               }
           }else if(head_==ptr){
               push_front(val);           
           }else{
               doubly_linked_list * n=head_;
              while(n != nullptr){
                  if(n==ptr){
                      break;
                    }
                   n=n->next_;
                }
                if(n==ptr){
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value_=val;
                  n1->prev_=tail_->prev_;
                  tail_->prev_->next_=n1;
                  n1->next_=tail_;
                  tail_->prev_=n1;
                }else{
                    throw std::logic_error("Provided Node not present");
                }   
           }
     }else{
         push_front(val);
     }       
}
/*
It inserts a new node just before the provided node, if same value is present at multiple 
locations then new node is inserted just before first occurance of that value.
@param__ P_ptr: provided value before which new node is to be inserted.
@param__ val: value to be inserted in new node.
@return__: void
throws std::logic_error if provided node is not present in the list.
*/
template<typename T>
void doubly_linked_list<T>::insert_before(T P_val,T val){
   if(head_ !=nullptr && tail_ !=nullptr){
           if(head_==tail_){
               if(head_->value_==P_val){
                   push_front(val);
               }else{
                   throw std::logic_error("Provided value not present");
               }
           }else if(head_->value_==P_val){
               push_front(val);           
           }else{
               doubly_linked_list * n=head_;
              while(n != nullptr){
                  if(n->value_==P_val){
                      break;
                    }
                   n=n->next_;
                }
                if(n==nullptr){
                    throw std::logic_error("Provided value not present");
                }else{
                  doubly_linked_list* n1=new doubly_linked_list<T>();
                  n1->value_=val;
                  n1->prev_=tail_->prev_;
                  tail_->prev_->next_=n1;
                  n1->next_=tail_;
                  tail_->prev_=n1;
                }   
           }
     }else{
         push_front(val);
     }
}