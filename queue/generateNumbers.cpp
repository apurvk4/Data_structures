#include<iostream>
#include "queue.h"
#include<string>
/*
generate first n(that is smallest) numbers with only 5 & 6 as there digits.
*/
void generateNumbers(int n){
    queue<std::string> q;
    std::string arr[n];
    arr[0]="5";
    arr[1]="6";
    q.push("5");
    q.push("6");
    for(int i=2;i<n;i+=2){
        std::string temp=q.front();
        q.pop();
        arr[i]=temp+"5";
        arr[i+1]=temp+"6";
        q.push(temp+"5");
        q.push(temp+"6");
    }
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
int main(){
    int n;
    std::cout<<"enter number of numbers required : ";
    std::cin>>n;
    generateNumbers(n);
}