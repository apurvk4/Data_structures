#include<iostream>
#include<algorithm>
int MaxActivities(std::pair<int,int> arr[],int n){
    std::sort(arr,arr+n,[](std::pair<int,int> p1,std::pair<int,int> p2){
        return p1.first < p2.first;
    });
    int count=0,last=INT32_MIN;
    for(int i=0;i<n;i++){
        if(arr[i].first >= last){
            count++;
            last=arr[i].second;
        }
    }
    return count;
}
int main(){
    int n;
    std::cin>>n;
    std::pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        int a;
        int b;
        std::cin>>a;
        std::cin>>b;
        arr[i]={a,b};
    }
    int a=MaxActivities(arr,n);
    return 0;
}