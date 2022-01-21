#include<iostream>
#include "priority_queue.hpp"
std::vector<int> Merge(std::vector<std::vector<int>> & in){
    priority_queue<int,Min> pq;
    for(int i=0;i<in.size();i++){
        for(int j=0;j<in[i].size();j++){
            pq.insert(in[i][j]);
        }
    }
    return pq.get_sortedList();
}
int main(){
    std::vector<std::vector<int>> vec;
    std::vector<int> a1{10,20,30};
    vec.push_back(a1);
    std::vector<int> a2{5,15};
    vec.push_back(a2);
    std::vector<int> a3{1,9,11,18};
    vec.push_back(a3);
    for(int val : Merge(vec)){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
}