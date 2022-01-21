#include<iostream>
#include "priority_queue.hpp"
#include<unordered_map>
std::vector<int> find_closest(int arr[],int n,int k,int x){
    priority_queue<int,Max> pq;
    std::unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int diff=abs(arr[i]-x);
        mp[diff]=arr[i];
        if(pq.size()<k){
            pq.insert(diff);
        }else if(pq.size()==k and diff < pq.get_Top()){
            pq.decrease_key(1,diff);
        }
    }
    std::vector<int> out;
    while(!pq.empty()){
        out.push_back(mp[pq.extract_Top()]);
    }
    return out;
}
int main(){
   int arr[]={20,40,5,100,150};
   int k=3;
   for( int val : find_closest(arr,5,k,100)){
       std::cout<<val<<" ";
   }
   std::cout<<"\n";
   return 0;
}