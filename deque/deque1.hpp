#pragma once
#include<initializer_list>
#include<unordered_map>
namespace apurv{
  enum type {UP,DOWN};
  enum level {ONE,TWO}; // pointer array is level one and value array is level two
  template<typename T>
  struct values{
    T realValue;
    bool deleted=false;
    values(){
        deleted=false;
    }
    values(values<T> * obj){
        realValue=std::move(obj->realValue);
        deleted=std::move(obj->deleted);
    }
    void operator=(values<T> * obj){
        if(this==&obj){
            return;
        }
        realValue=std::move(obj->realValue);
        deleted=std::move(obj->deleted);
        delete obj;
    }
  };
  template<typename T>
  struct data{
        values<T>** arr;
        int i_pab; // pointer array index begin
        int i_pae; // pointer array index end
        int i_vab; // value array index begin
        int i_vae; // value array index end
        data(apurv::type t){
            if(t==apurv::UP){
                i_pab=9;
                i_pae=10;
                i_vab=9;
                i_vae=10;
            }else if(t==apurv::DOWN){
                i_pab=0;
                i_pae=-1;
                i_vab=0;
                i_vae=-1;
            }
        }
   };
}
template<typename T>
class deque{
   public:
    deque():mp_ib_{0},mp_ie_{0},size_{0},slot_size_{10}{ 
    }
    deque(std::initializer_list<T> & l):mp_ib_{0},mp_ie_{0},size_{0},slot_size_{10}{
        for(T data: l){
           push_back(data);
        }
    }
    const bool empty() const{
        return size_==0;
    }
    const unsigned int size() const{
       return size_;
    }
    const T & front(){
        if(size_==0){
            throw std::logic_error("there are no elements in deque");
        }
        if(mp_ib_<0){
            return mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue;
        }else{
            return mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][mp_[mp_ib_]->i_vab].realValue;
        }
    }
    const T & back(){
        if(size_==0){
            throw std::logic_error("there are no elements in deque");
        }
        if(mp_.find(0)==mp_.end()){
            return mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][mp_[mp_ib_]->i_vab].realValue;
        }else{
            return mp_[0]->arr[mp_[0]->i_pab][mp_[0]->i_vab].realValue;        
        }
    }
    class iterator{
        public:
         const T & operator*(){
             return ptr_->realValue;
         }
         iterator(deque<T> * obj):obj_{obj}{
             ptr_=obj_->mp_[obj_->mp_ib_]->arr[obj_->mp_[obj_->mp_ib_]->i_pab][obj_->mp_[obj_->mp_ib_]->i_vab];
         }
         iterator operator++(int){
             
         }
         bool operator!=(const iterator & rhs){
             return ptr_==rhs.ptr_;
         }
          apurv::values<T>* operator->(){
               return this->ptr_;
           }
        private:
         apurv::values<T> * ptr_;
         deque<T> * obj_;
    };
    iterator begin(){
        return iterator(this);
    }
    iterator end(){
        return iterator(nullptr);
    }
    ~deque(){
        if(size_ !=0){
          if(mp_ib_<0){
                while(mp_ib_!=0){
                    while(mp_[mp_ib_]->i_pae!=slot_size_-1){
                      delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae++];
                    }
                    delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae];
                    delete [] mp_[mp_ib_]->arr;
                    delete mp_[mp_ib_];
                    mp_.erase(mp_ib_++);
                }
                if(mp_.find(0) !=mp_.end()){
                    goto Down;
                }
          }else{
              Down:
              while(mp_ie_ !=0){
                  while(mp_[mp_ie_]->i_pae!=0){
                       delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae--];
                  }
                  if(mp_.find(mp_ie_) !=mp_.end()){
                     delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pab];
                     delete [] mp_[mp_ie_]->arr;
                     delete mp_[mp_ie_];
                     mp_.erase(mp_ie_--); 
                  }
              }
             while(mp_[mp_ie_]->i_pae!=0){
                       delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae--];
             }
             delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae];
             delete [] mp_[mp_ie_]->arr;
             delete mp_[mp_ie_];
             mp_.erase(mp_ie_);
          }
        }
        mp_.clear();
    }
    void push_front(T & val){
        if(mp_ib_==0){
            allocator(apurv::UP,apurv::ONE); // mp_ib_-- and i_pab=slot_size_-1 and i_vae=slot_size_
        }
            // if(mp_[mp_ib_]->i_pae>=0){
                if(mp_[mp_ib_]->i_vae-1>=0){
                    mp_[mp_ib_]->i_vae-=1;
                    mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                    size_++;   
                }else{
                    if(mp_[mp_ib_]->i_pae>0){
                        allocator(apurv::UP,apurv::TWO); // i_pae-- and i_vae=slot_size_-1
                        mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                        size_++;
                    }else{
                        allocator(apurv::UP,apurv::ONE); // mp_ib_-- and i_pab=slot_size_-1 and i_vae=slot_size_
                        mp_[mp_ib_]->i_vae-=1;
                        mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                        size_++;
                    }          
                }
            // }else{
            //     allocator(apurv::UP,apurv::ONE);
            //     mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae--].realValue=val;
            //     size_++;              
            // }
    }
    void push_front(T && val){
        if(mp_ib_==0){
            allocator(apurv::UP,apurv::ONE); // mp_ib_-- and i_pab=slot_size_-1 and i_vae=slot_size_
        }
            // if(mp_[mp_ib_]->i_pae>=0){
                if(mp_[mp_ib_]->i_vae-1>=0){
                    mp_[mp_ib_]->i_vae-=1;
                    mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                    size_++;   
                }else{
                    if(mp_[mp_ib_]->i_pae>0){
                        allocator(apurv::UP,apurv::TWO); // i_pae-- and i_vae=slot_size_-1
                        mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                        size_++;
                    }else{
                        allocator(apurv::UP,apurv::ONE); // mp_ib_-- and i_pab=slot_size_-1 and i_vae=slot_size_
                        mp_[mp_ib_]->i_vae-=1;
                        mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae].realValue=val;
                        size_++;
                    }          
                }
            // }else{
            //     allocator(apurv::UP,apurv::ONE);
            //     mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae][mp_[mp_ib_]->i_vae--].realValue=val;
            //     size_++;              
            // }
    }
    void push_back(T & val){
        if(mp_.find(0)==mp_.end()){
            allocator(apurv::DOWN,apurv::ONE); // gives i_pae==0 and i_vae==-1
        }
        // if(mp_[mp_ie_]->i_pae<=slot_size_-1){
            if(mp_[mp_ie_]->i_vae+1<=slot_size_-1){
               mp_[mp_ie_]->i_vae++;
               mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
               size_++;
            }else{
               if(mp_[mp_ie_]->i_pae <slot_size_-1){
                    allocator(apurv::DOWN,apurv::TWO); // gives i_vae==0 and i_pae++
                    mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
                    size_++;
               }else{
                   allocator(apurv::DOWN,apurv::ONE);  // gives i_pae==0 and i_vae==-1
                   mp_[mp_ie_]->i_vae+=1;
                   mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
                   size_++;
               }
            }
        // }else{
        //     allocator(apurv::DOWN,apurv::ONE); // gives i_pae==0 and i_vae==-1
        //     mp_[mp_ie_]->i_vae++;
        //     mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
        //     size_++;           
        // }
    }
    void push_back(T && val){
        if(mp_.find(0)==mp_.end()){ // not present
            allocator(apurv::DOWN,apurv::ONE); // gives i_pae==0 and i_vae==-1
        }
        if(mp_[mp_ie_]->i_vae+1<=slot_size_-1){
             mp_[mp_ie_]->i_vae++;
            mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
            size_++;
        }else{
            if(mp_[mp_ie_]->i_pae <slot_size_-1){
                allocator(apurv::DOWN,apurv::TWO); // gives i_vae==0 and i_pae++
                mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
                size_++;
            }else{
                allocator(apurv::DOWN,apurv::ONE);  // gives i_pae==0 and i_vae==-1
                mp_[mp_ie_]->i_vae+=1;
                mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vae].realValue=val;
                size_++;
            }
        }
    }
    void pop_back(){   
        if(size_==0){return;}
        if(mp_ib_<0 && mp_.find(0)==mp_.end()){
             // remaining when no element in down array
             if(mp_[mp_ib_]->i_pab==mp_[mp_ib_]->i_pae && mp_[mp_ib_]->i_vab==mp_[mp_ib_]->i_vae){
                 delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab];
                 delete [] mp_[mp_ib_]->arr;
                 delete [] mp_[mp_ib_];
                 mp_.erase(mp_ib_++);
                 size_--;
             }else{
                 if(mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][mp_[mp_ib_]->i_vab+1].deleted){
                     delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab];
                     for(int i=0;i<slot_size_-1;i++){
                         mp_[mp_ib_]->arr[i]=mp_[mp_ib_]->arr[i+1];
                     }
                     mp_[mp_ib_]->i_pae--;
                     size_--;
                     return;
                 }
                //  mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][mp_[mp_ib_]->i_vab].deleted=true;
             }
        }else{
           if(mp_[mp_ie_]->i_vae==0 && mp_[mp_ie_]->i_pae==0){
               delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae];
               delete [] mp_[mp_ie_]->arr;
               delete mp_[mp_ie_];
               mp_.erase(mp_ie_);
               if(mp_ie_!=0){
                   mp_ie_--;
               }
               size_--;
           }else if(mp_[mp_ie_]->i_vae==0 && mp_[mp_ie_]->i_pae != 0){
               delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae--];
               mp_[mp_ie_]->i_vae=slot_size_-1;
               size_--;
           }else{
               int index=mp_[mp_ie_]->i_vae;
               if(index==slot_size_-1){
                   mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index].deleted=true;
                   mp_[mp_ie_]->i_vae--;
                   size_--;
                   return;
               }
               while(index !=slot_size_-1 && mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index].deleted ==false){
                   index++;
               }
               if(index==slot_size_-1){
                   mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index].deleted=true;
               }else{
                   mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index-1].deleted=true;
               }
               mp_[mp_ie_]->i_vae--;
               size_--;
           }
        }
    }
    void pop_front(){
        if(size_ !=0){
            if(mp_ib_<0){ 
                int index=slot_size_-1;
                if(mp_[mp_ib_]->i_pab==mp_[mp_ib_]->i_pae){
                    if(mp_[mp_ib_]->i_vae!=slot_size_-1){
                      apurv::values<T> * ptr=new apurv::values<T>[slot_size_];
                      while(index!=mp_[mp_ib_]->i_vae ){
                             ptr[index].realValue=std::move(mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][index].realValue);
                             index--;
                        }
                       while(index !=-1){
                           ptr[index].deleted=true;
                           index--;
                       }
                       delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab];
                       mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab]=ptr;
                       size_--;
                    }else{
                        delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae];
                        delete [] mp_[mp_ib_]->arr;
                        delete mp_[mp_ib_];
                        mp_.erase(mp_ib_++);
                        size_--;
                    }
                }else if(mp_[mp_ib_]->i_vae==slot_size_-1 && mp_[mp_ib_]->i_pab != mp_[mp_ib_]->i_pae){
                        delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae++];
                        size_--;
                }else{
                   apurv::values<T> * ptr=new apurv::values<T>[slot_size_];
                   while(index !=mp_[mp_ib_]->i_vae){
                        ptr[index].realValue=std::move(mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pab][index].realValue); 
                        index--; 
                    }
                   while(index != -1){
                        ptr[index].deleted=true;
                        index--;
                    }
                    delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae];
                    mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae]=ptr;
                    size_--;
                }
            }else{
               if(mp_[mp_ie_]->i_pae==mp_[mp_ie_]->i_pab && mp_[mp_ie_]->i_vae==mp_[mp_ie_]->i_vab){
                  delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae];
                  delete [] mp_[mp_ib_]->arr;
                  delete mp_[mp_ib_];
                  mp_.erase(mp_ie_);
                  mp_ie_= (mp_ie_ !=0)? mp_ie_-1:0;
                  size_--;
               }else if(mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][mp_[mp_ie_]->i_vab+1].deleted  && mp_[mp_ie_]->i_pab != mp_[mp_ie_]->i_pae){
                  delete [] mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae--];
                  size_--;
               }else{
                  int index=1;
                  apurv::values<T> * ptr=new apurv::values<T>[slot_size_];
                  while(index !=slot_size_+1 && mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index].deleted==false){
                        ptr[index-1].realValue=std::move(mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae][index].realValue);
                        index++;
                  }
                  if(index !=slot_size_+1){
                      index--;
                      while(index !=slot_size_){
                          ptr[index].deleted=true;
                          index++;
                      }
                  }
                  delete [] mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae];
                  mp_[mp_ie_]->arr[mp_[mp_ib_]->i_pae]=ptr;
                  size_--;
               }
            }
        }
    }
   private: 
    void allocator(apurv::type t,apurv::level l){
      if(t==apurv::DOWN){
          if(l==apurv::TWO){
             mp_[mp_ie_]->i_pae++;
             mp_[mp_ie_]->arr[mp_[mp_ie_]->i_pae]=new apurv::values<T>[slot_size_];
             mp_[mp_ie_]->i_vae=0;
          }else if(l==apurv::ONE){
              if(mp_.find(0)!=mp_.end()){
                 mp_ie_++;
              }
             apurv::data<T> * p=new apurv::data<T>(apurv::DOWN);
             apurv::values<T> ** ptr=new apurv::values<T> *[slot_size_];
             p->i_pae++;
             ptr[p->i_pab]=new apurv::values<T> [slot_size_];
             p->arr=ptr;
             mp_[mp_ie_]=p;
          }
      }else if(t==apurv::UP){
          if(l==apurv::TWO){
             mp_[mp_ib_]->i_pae--;
             mp_[mp_ib_]->arr[mp_[mp_ib_]->i_pae]=new apurv::values<T>[slot_size_];
             mp_[mp_ib_]->i_vae=slot_size_-1;             
          }else if(l==apurv::ONE){
              mp_ib_--;
              apurv::values<T> ** ptr=new apurv::values<T> *[slot_size_];
              apurv::data<T> * p=new apurv::data<T>(apurv::UP);
              p->arr=ptr;
              p->i_pae--;
              p->arr[p->i_pab]=new apurv::values<T>[slot_size_];
              mp_[mp_ib_]=p;              
          }
      }
    }
    std::unordered_map<int,apurv::data<T>* > mp_; // hashMap to store key value pairs.One slot of the hashMap can store 100 elements in its default implementation.
    int mp_ib_; // map index begin
    int mp_ie_; // map index end
    int slot_size_; // size of both value array and pointer array.
    unsigned int size_; // keeps track of number of elements in deque
    // bool back_flag=false;
    // bool front_flag=false;
};
