#include<iostream>
#include<vector>
#include<queue>
/*
using kahn algorithm based on bfs sub-routine.
*/
std::vector<int> topologicalSorting(std::vector<int> g[],int n){
    std::vector<int> out;
    int *a=new int[n]{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            a[g[i][j]]++;
        }
    }
    std::queue<int> q;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        out.push_back(temp);
        for(int i=0;i<g[temp].size();i++){
            a[g[temp][i]]--;
            if(a[g[temp][i]]==0){
                q.push(g[temp][i]);
            }
        }
    }
    delete [] a;
    return out;
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
   for(auto val:topologicalSorting(g,v)){
       std::cout<<val<<" ";
   }
   std::cout<<"\n";
   return 0;
}