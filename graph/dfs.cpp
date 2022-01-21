#include<iostream>
#include<vector>
void Dfs(int & src,std::vector<int> & out,std::vector<int> g[],bool **visited){
    out.push_back(src);
    bool * v=*visited;
    for(int i=0;i<g[src].size();i++){
        if(v[g[src][i]]==0){
            v[g[src][i]]=1;
            Dfs(g[src][i],out,g,visited);
        }
    }
}
std::vector <int> dfs(std::vector<int> g[], int N)
{
    std::vector<int> out;
    bool *visited=new bool[N]{0};
    int src=0;
    visited[0]=1;
    Dfs(src,out,g,&visited);
    delete [] visited;
    return out;
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
   for(auto val: dfs(g,v)){
       std::cout<<val<<" ";
   }
   std::cout<<"\n";
}