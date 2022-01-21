#include<iostream>
#include<vector>
/*
for a undirected graph.
*/
bool dfs(int src,std::vector<int> g[],int n,int parent,bool **visit){
    bool *v=*visit;
    for(int i=0;i<g[src].size();i++){
        if(v[g[src][i]]==0){
            v[g[src][i]]=1;
            bool r=dfs(g[src][i],g,n,src,visit);
            if(r){return true;}
        }else{
            if(g[src][i]==parent){
                continue;
            }else{
                return true;
            }
        }
    }
    return false;
}
bool detectcylce(std::vector<int> g[],int n){
    bool *visited=new bool[n]{0};
    bool res;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[0]=1;
            res=dfs(i,g,n,-1,&visited);
            if(res){
                delete [] visited;    
                return res;
            } 
        }
    }
    delete [] visited;
    return res;
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
   std::cout<<std::boolalpha<<detectcylce(g,v)<<std::endl;
   return 0;
}