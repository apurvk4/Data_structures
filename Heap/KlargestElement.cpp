#include<iostream>
#include "priority_queue.hpp"
std::vector<int> Klargest(int arr[],int n,int k){
    std::vector<int> out;
    priority_queue<int,Min> pq;
    for(int i=0;i<k;i++){
        pq.insert(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>pq.get_Top()){
            pq.decrease_key(1,arr[i]);
        }
    }
    while(not pq.empty()){
        out.push_back(pq.extract_Top());
    }
    return out;
}
int main(){
    int arr[]={5,15,10,20,8,25,18};
    int k=3;
    for( int val : Klargest(arr,7,k)){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
    return 0;
}