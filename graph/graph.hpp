#pragma once 
#include<stdexcept>
#include<unordered_set>
#include "../queue/queue.h"
struct Invalid_traverse:public std::invalid_argument{
    const char * what() const noexcept{
        return std::invalid_argument::what();
    }
    Invalid_traverse(std::string s):invalid_argument(s.c_str()){
    }
};
enum type{directed,undirected};
template<typename T,type T1>
class graph{
    private:
     struct Edge{
         double weight;
         typename graph<T,T1>::node * start;
         typename graph<T,T1>::node * end;
         Edge * next;
         Edge(typename graph<T,T1>::node * s,typename graph<T,T1>::node * e):start{s},end{e},weight{1},next{nullptr}{
         }
         Edge(typename graph<T,T1>::node * s,typename graph<T,T1>::node * e,double w):start{s},end{e},weight{w},next{nullptr}{
         }
         friend std::ostream & operator<<(std::ostream & out,typename graph<T,T1>::Edge * ptr){
             out<<ptr->weight;
             return out;
         }
     };
     struct node{
         T data;
         node * next;
         typename graph<T,T1>::Edge * list_begin;
         typename graph<T,T1>::Edge * list_end;
         node(T val):data{val},next{nullptr},list_begin{nullptr}{
         }
         friend std::ostream & operator<<(std::ostream & out,typename graph<T,T1>::node * ptr){
             out<<ptr->data;
             return out;
         }
     };
     typename graph<T,T1>::node * head;
     typename graph<T,T1>::node * tail;
    public:
    class iterator{
        private:
          typename graph<T,T1>::node * ptr;
        public:
          iterator():ptr{nullptr}{
          }
          iterator(typename graph<T,T1>::node * p):ptr{p}{
          }  
          void moveTo(iterator  it){
              typename graph<T,T1>::Edge * temp=this->ptr->list_begin;
              bool flag=false;
              while(temp !=nullptr){
                  if(temp->end==(*it)){
                      flag=true;
                      this->ptr=*it;
                      return;
                  }
                  temp=temp->next;
              }
              if(!flag){
                if(T1==undirected){
                    temp=(*it)->list_begin;
                    while(temp !=nullptr){
                        if(temp->end==this->ptr){
                            flag=true;
                            this->ptr=*it;
                            return;
                        }
                        temp=temp->next;
                    }
                    if(!flag){
                        throw Invalid_traverse("No edge between current and next vertex.");
                    }
                }else{
                    throw Invalid_traverse("No directed edge towards next vertex from current vertex.");
                }
              }
          }
          typename graph<T,T1>::node * operator*(){
              return this->ptr;
          }
          bool operator==(const iterator & it){
              return this->ptr==it.ptr;
          }
          bool operator !=(const iterator & it){
              return this->ptr != it.ptr;
          }
          void operator++(int){
              this->ptr=this->ptr->next;
          }
          iterator operator++(){
              this->ptr=this->ptr->next;
              return *this;
          }
          void operator+=(int k){
              typename graph<T,T1>::node * temp=this->ptr;
              while(temp !=nullptr && k--){
                  this->ptr=temp;
                  temp=temp->next;
              }
          }
          friend std::ostream & operator<<(std::ostream & out,iterator & it){
              out<<*it;
              return out;
          }
    };
     iterator begin(){
         return iterator(head);
     }
     iterator end(){
         return iterator();
     }
     class EdgeIterator{
        private:
          typename graph<T,T1>::Edge * ptr;
        public:
          EdgeIterator():ptr{nullptr}{
          }
          EdgeIterator(typename graph<T,T1>::node * p):ptr{p->list_begin}{
          }
          EdgeIterator(typename graph<T,T1>::iterator & it):ptr{(*it)->list_begin}{
          }    
          typename graph<T,T1>::Edge * operator*(){
              return this->ptr;
          }
          bool operator==(const EdgeIterator & it){
              return this->ptr==it.ptr;
          }
          bool operator !=(const EdgeIterator & it){
              return this->ptr != it.ptr;
          }
          void operator++(int){
              this->ptr=this->ptr->next;
          }
          friend std::ostream & operator<<(std::ostream & out,EdgeIterator & it){
              out<<*it;
              return out;
          } 
     };
     EdgeIterator Edge_begin(typename graph<T,T1>::iterator & it){
         return EdgeIterator(it);
     }
     EdgeIterator Edge_begin(typename graph<T,T1>::node * p){
         return EdgeIterator(p);
     }
     EdgeIterator Edge_end(){
         return EdgeIterator();
     }
     graph():head{nullptr},tail{nullptr}{
     }
     void connectEdge(typename graph::iterator start,typename graph::iterator end,double weight=1){
          if((*start)->list_begin==nullptr){
              (*start)->list_begin=new Edge(*start,*end,weight);
              (*start)->list_end=(*start)->list_begin;
          }else{
              (*start)->list_end->next=new Edge(*start,*end,weight);
              (*start)->list_end=(*start)->list_end->next;
          }
          if(T1==undirected){
              if((*end)->list_begin==nullptr){
                (*end)->list_begin=new Edge(*end,*start,weight);
                (*end)->list_end=(*end)->list_begin;
              }else{
                (*end)->list_end->next=new Edge(*end,*start,weight);
                (*end)->list_end=(*end)->list_end->next;
              }
          }
     }
     void insertVertex(const T & val){
        if(head==nullptr){
            head=new node(val);
            head->next=nullptr;
            tail=head;
        }else{
            tail->next=new node(val);
            tail->next->next=nullptr;
            tail=tail->next;
        }
     }
     bool hasEdges(typename graph::iterator & it){
        return (*it)->list_begin !=nullptr;
     }
     ~graph(){
        typename graph<T,T1>::node * temp=head;
        while(temp !=nullptr){
            typename graph<T,T1>::node * pre=temp;
            temp=temp->next;
            typename graph<T,T1>::Edge * Etemp=pre->list_begin;
            while(Etemp !=nullptr){
                typename graph<T,T1>::Edge * Epre=Etemp;
                Etemp=Etemp->next;
                delete Epre;
            }
            delete pre;
        }
     }
    //  void BFS(){
    //     std::unordered_set<typename graph<T,T1>::node *> s;
    //     queue<typename graph<T,T1>::node *> q;
    //     q.push(this->head);
    //     s.insert(this->head);
    //     while(!q.empty()){
    //         int count=q.size();
    //         for(int i=0;i<count;i++){
    //             typename graph<T,T1>::node * p=q.front();
    //             q.pop();

    //         }           
    //     }
    //  }
};