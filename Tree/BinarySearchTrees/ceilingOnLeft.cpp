#include<iostream>
#include<set>
void PrintCeilingOnLeftSide(int arr[],int n){
    if(n==0){return;}
    std::set<int> s;
    for(int i=0;i<n;i++){
        auto it=s.lower_bound(arr[i]);
        if(it==s.end()){
            std::cout<<-1<<" ";
        }else{
            std::cout<<*it<<" ";
        }
        s.insert(arr[i]);
    }
    std::cout<<"\n";
}

int main(){
    int arr[]={2,8,30,15,25,12};
    PrintCeilingOnLeftSide(arr,6);
    return 0;
}