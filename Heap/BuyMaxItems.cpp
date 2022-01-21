#include<iostream>
#include "priority_queue.hpp"
int BuyMax(int arr[],int n,int sum){
    priority_queue<int,Min> pq;
    for(int i=0;i<n;i++){
        pq.insert(arr[i]);
    }
    int res=0,curr_sum=0;
    while(!pq.empty()){
        int t=pq.extract_Top();
        if(curr_sum+t<=sum){
            curr_sum+=t;
            res++;
        }else{break;}
    }
    return res;    
}
int main(){
    int arr[]={20,10,5,30,100};
    int sum=35;
    std::cout<<BuyMax(arr,5,sum)<<"\n";
    return 0;
}