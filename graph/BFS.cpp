#include<iostream>
#include<vector>
#include "../queue/queue.h"
void bfs(std::vector<int>  g[],int n){
   bool visited[n]={0};
   queue<int> q;
   int j=0;
   q.push(j);
   visited[j]=1;
   while(!q.empty()){
      for(int i=0;i<g[q.front()].size();i++){
         if(visited[g[q.front()][i]]==0){
            q.push(g[q.front()][i]);
            visited[g[q.front()][i]]=1;
         }
      }
      std::cout<<q.front()<<" ";
      q.pop();
   }
}
int main(){
   int v,e;
   std::cin>>v>>e;
   std::vector<int> g[v];
   for(int i=0;i<e;i++){
      
      int u,v;
      std::cin>>u>>v;
      g[u].push_back(v);
   }
   bfs(g,v);
   return 0;
}