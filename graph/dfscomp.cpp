#include<iostream>
#include<vector>
/*
count number of different disconnected components of a graph.
*/
void Dfs(int & src,std::vector<int> g[],bool **visited){
    bool * v=*visited;
    for(int i=0;i<g[src].size();i++){
        if(v[g[src][i]]==0){
            v[g[src][i]]=1;
            Dfs(g[src][i],g,visited);
        }
    }
}
int dfs(std::vector<int> g[], int N)
{
    bool *visited=new bool[N];
    for(int i=0;i<N;i++){
        visited[i]=0;
    }
    int src=0,count=0;
    for(int i=src;i<N;i++){
        if(visited[i]==0){
            visited[i]=1;
            Dfs(i,g,&visited);
            count++;
        }
    }
    delete [] visited;
    return count;
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
   
   std::cout<<dfs(g,v)<<"\n";
}