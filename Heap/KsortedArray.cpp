#include<iostream>
#include "priority_queue.hpp"
std::vector<int> Ksorted(int arr[],int n,int k){
    priority_queue<int,Min> pq;
    for(int i=0;i<=k;i++){
        pq.insert(arr[i]);
    }
    std::vector<int> out;
    for(int i=k+1;i<n;i++){
        out.push_back(pq.extract_Top());
        pq.insert(arr[i]);
    }
    while(!pq.empty()){
        out.push_back(pq.extract_Top());
    }
    return out;
}
int main(){
    int arr[]={10,9,7,8,4,70,50,60};
    int k=4;
    for( int val : Ksorted(arr,8,k)){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
    return 0;
}