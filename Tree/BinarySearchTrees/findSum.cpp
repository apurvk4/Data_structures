#include<iostream>
#include<set>
std::pair<int,int> findSum(std::set<int> & s,int sum){
    for(auto val:s){
        if(s.find(sum-val) !=s.end() && sum-val !=val){
            return std::pair<int,int>(val,sum-val);
        }
    }
    return std::pair<int,int>(INT32_MIN,INT32_MIN);
}
int main(){
std::set<int> s{10,5,20,16,40};
auto p=findSum(s,21);
std::cout<<"("<<p.first<<","<<p.second<<")"<<"\n";
return 0;
}