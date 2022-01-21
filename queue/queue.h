#include "../dll_base.h"
#include<initializer_list>
template<typename T>
class queue:public Node<T>{
    public:
     void push(T & );
     void push(T &&);
     void pop();
     T & front();
     T & back();
     bool empty();
     void reverse();
     const unsigned int size();
     queue();
     queue(std::initializer_list<T>);
    //  queue(const queue<T> & );
     ~queue()=default;
    protected:
     unsigned int size_;
     T & get_data()=delete;
};
template<typename T>
void queue<T>::push(T & val){
  this->push_front(val);
  size_++;
}
template<typename T>
void queue<T>::push(T && val){
  this->push_front(val);
  size_++;
}
template<typename T>
void queue<T>::pop(){
    this->pop_back();
    size_--;
}
template<typename T>
bool queue<T>::empty(){
    return size_==0;
}
template<typename T>
T & queue<T>::front(){
    return this->tail_->get_data();
}
template<typename T>
T & queue<T>::back(){
    return this->head_->get_data();
}
template<typename T>
const unsigned int queue<T>::size(){
  return size_;
}
template<typename T>
queue<T>::queue():Node<T>(),size_{0}{
}
template<typename T>
queue<T>::queue(std::initializer_list<T> l):size_{0}{
   for(auto element : l){
     this->push(element);
   }
}
// template<typename T>
// queue<T>::queue(queue<T> & obj){
//   Node<T> * temp,temp1;
//   temp1=obj.head_;
//   while(temp1 !=nullptr){
//       temp=new Node<T>(temp1->get_data());
//       if(this->head_==nullptr){
//         temp->next_=nullptr;
//         temp->prev_=nullptr;
//         this->head_=temp;
//         this->tail_=temp;
//       }else{
//         temp->next_=this->head_;
//         temp->prev_=nullptr;
//         this->head_->prev_=temp;
//         this->head_=temp;
//       }
//       temp1=temp1->next_;
//   }
// }
template<typename T>
void queue<T>::reverse(){
    Node<T>::reverse();
}