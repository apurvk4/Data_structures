#include<bits/stdc++.h>
int fractionalKnapsack(std::pair<int,int> arr[],int n,int k){
    std::sort(arr,arr+n,[](std::pair<int,int> p1,std::pair<int,int> p2){
        return ((double)p2.first/p2.second) > ((double)p1.first/p1.second);
    });
    double res=0;
    int curr_cap=
    for(int i=0;i<n;i++){
        int a=floor(k/arr[i].first);

    }
}
int main(){
    int n,k;
    std::cin>>n>>k;
    std::pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        int a;
        int b;
        std::cin>>a;
        std::cin>>b;
        arr[i]={a,b};
    }
    int a=fractionalKnapsack(arr,n,k);
    return 0;
}