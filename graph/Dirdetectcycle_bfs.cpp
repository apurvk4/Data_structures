#include<iostream>
#include<vector>
#include<queue>
/*
cycle detection algorithm for a directed graph using kahn
algorithm.
*/

bool detectcycle(std::vector<int> g[],int n){
    int arr[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            arr[g[i][j]]++;
        }
    }
    std::queue<int> q;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        count++;
        for(int i=0;i<g[temp].size();i++){
            arr[g[temp][i]]--;
            if(arr[g[temp][i]]==0){
                q.push(g[temp][i]);
            }
        }
    }
    return count != n;
}
int main(){
   int v,e;
   std::cout<<"Enter number of vertex and number of edges : ";
   std::cin>>v>>e;
   std::vector<int> g[v];
   std::cout<<"Enter adjacent list of the graph "<<std::endl;
   for(int i=0;i<e;i++){ 
      int u,v1;
      std::cin>>u>>v1;
      g[u].push_back(v1);
   }
   std::cout<<std::boolalpha<<detectcycle(g,v)<<std::endl;
   return 0;
}