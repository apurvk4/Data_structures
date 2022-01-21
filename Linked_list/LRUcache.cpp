#include<iostream>
#include<string>
#include "singly_linked-list.h"
template<typename T>
class LRUcache{
    private:
     int max_size=0;
     int curr_size=0;
     linked_list<T> l;
      linked_list<T> * prev=nullptr;
      linked_list<T> * curr=nullptr;
     void insert(T & val){
        if(curr_size<max_size){
            l.push_front(val);
            curr_size++;
        }else if(curr_size==max_size){
            l.pop_back();
            curr_size--;
            l.push_front(val);
            curr_size++;
        }
     }
     bool find(T & val){
       linked_list<T> * ptr=get_head(l);
       linked_list<T> * pn=nullptr;
       while(ptr !=nullptr){
           if(get_value(ptr) ==val){
              prev=pn;
              curr=ptr;
              return true; 
           }
           pn=ptr;
           ptr=get_next(ptr);
       }
       prev=nullptr;
       curr=nullptr;
       return false;
     }
     void update(T & val){
         if(prev !=nullptr){
             set_next(prev,get_next(curr));
             delete curr;
             curr_size--;
             l.push_front(val);
             curr_size++;
         }
     }
    public:
     LRUcache(int size):max_size{size},curr_size{0}{
     }
     std::string get(T & val){
         if(find(val)){
            update(val);
            prev=nullptr;
            curr=nullptr;
            return "hit";
         }else{
             insert(val);
             return "miss";
         }
     }
};

int main(){
    LRUcache<int> c(5);
    while(1){
        std::cout<<"enter number : ";
        int n;
        std::cin>>n;
        if(n==-256){
            break;
        }
        std::cout<<c.get(n)<<"\n";
    }
    return 0; 
}