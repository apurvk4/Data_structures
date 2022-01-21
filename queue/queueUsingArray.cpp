#include<iostream>
#include<vector>
template<typename T>
class queue{
    public:
     T & front();
     T & back();
     bool empty();
     void push(T &);
     void push(T &&);
     void pop();
     queue(int);
     ~queue()=default;
    private:
     int size_;
     std::vector<T> arr;
     int i_start_=-1;
     int i_end_=-1;
};
template<typename T>
T & queue<T>::front(){
    return arr[i_start_];
}
template<typename T>
T & queue<T>::back(){
    return arr[i_end_];
}
template<typename T>
void queue<T>::pop(){
  if(i_end_<0){throw std::invalid_argument("queue underflow");}
  i_start_++;
}
template<typename T>
void queue<T>::push(T & val){
    if(i_end_+1==size_){throw std::invalid_argument("queue overflow");}
    i_end_++;
    arr.push_back(val);
    if(i_start_<0){
        i_start_++;
    }
}
template<typename T>
void queue<T>::push(T && val){
    if(i_end_+1==size_){throw std::invalid_argument("queue overflow");}
    i_end_++;
    arr.push_back(val);
    if(i_start_<0){
        i_start_++;
    }
}
template<typename T>
bool queue<T>::empty(){
    return i_end_-i_start_+1==0;
}
template<typename T>
queue<T>::queue(int sz):size_{sz},i_start_{-1},i_end_{-1}{
}
int main(){
    queue<int> q(10);
    q.push(23);
    q.push(34);
    q.push(90);
    q.push(22);
    q.push(35);
    q.push(91);
    q.push(41);
    q.push(88);
    q.push(23);
    q.push(30);
    // q.pop();
    while(!q.empty()){
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<"\n";
    // std::cout<<q.front()<<" "<<q.back()<<"\n";
}