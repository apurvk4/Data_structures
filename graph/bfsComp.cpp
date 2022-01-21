#include<iostream>
#include<queue>
#include<vector>
/*
count number of different disconnected components of a graph.
*/
void bfs(int st,std::vector<std::vector<int>> & g,bool **visited,int n){
   std::queue<int> q;
   bool *v=*visited;
   q.push(st);
   v[st]=1;
   while(!q.empty()){
      for(int i=0;i<g[q.front()].size();i++){
         if(v[g[q.front()][i]]==0){
            q.push(g[q.front()][i]);
            v[g[q.front()][i]]=1;
         }
      }
      q.pop();
   }
}
int bfsDis(std::vector<std::vector<int> > & g,int n){
  bool *visited=new bool[n];
  for(int i=0;i<n;i++){
      visited[i]=0;
  }
  int count=0;
  for(int i=0;i<n;i++){
      if(visited[i]==0){
          bfs(i,g,&visited,n);
          count++;
      }
  }
  delete [] visited;
  return count;
}

int main(){
   int v,e;
   std::cin>>v>>e;
   std::vector<int> temp;
   std::vector<std::vector<int> > g(v,temp);
   for(int i=0;i<e;i++){
      int u,v;
      std::cin>>u>>v;
      g[u].push_back(v);
   }
   std::cout<<bfsDis(g,v)<<"\n";
   return 0;
}