#include<iostream>
#include<vector>
/*
for a directed graph.
*/
bool dfs(int src,std::vector<int> g[],int n,bool **visit,bool **recur){
    bool *rec=*recur;
    bool *v=*visit;
    bool res;
    for(int i=0;i<g[src].size();i++){
        if(v[g[src][i]]==0){
            rec[g[src][i]]=1;
            v[g[src][i]]=1;
            res=dfs(g[src][i],g,n,visit,recur);
            rec[g[src][i]]=0;
            if(res){return true;}
        }else{
            if(rec[g[src][i]]){
                return true;
            }else{
                continue;
            }
        }
    }
    return false;
}
bool detectcylce(std::vector<int> g[],int n){
    bool *visited=new bool[n]{0};
    bool *recur=new bool[n]{0};
    bool res;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            recur[i]=1;
            res=dfs(i,g,n,&visited,&recur);
            recur[i]=0;
            if(res){
                delete [] visited;
                delete [] recur;
                return true;
            }
        }
    }
    delete [] visited;
    delete [] recur;
    return false;
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