#include<iostream>
#include<set>
int findKthSmallest(int arr[],int n,int k){
    std::set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int count=0;
    for(int val : s){
       if(count==k){
           count=val;
           break;
       }
       count++;
    }
    return count;
}
int main(){
    int arr[]={50,20,100,120,80,60,70,10,40,4};
    int k=4;
    std::cout<<findKthSmallest(arr,10,k)<<"\n";
    return 0;
}