#include<iostream>
#include<queue>
#include<vector>
/*
for a undirected graph.
*/
bool bfs(int src,std::vector<int> g[],int n,int parent,int **a,bool **visit){
    bool *v=*visit;
    int *arr=*a;
    std::queue<int> q;
    q.push(src);
    v[src]=1;
    while(!q.empty()){
        for(int i=0;i<g[q.front()].size();i++){
            if(v[g[q.front()][i]]==0){
                v[g[q.front()][i]]=1;
                q.push(g[q.front()][i]);
                arr[g[q.front()][i]]=q.front();
            }else{
                if(g[q.front()][i]==arr[q.front()]){
                    continue;
                }else{
                    return true;
                }
            }
        }
        q.pop();
    }
    return false;
}
bool detectcylce(std::vector<int> g[],int n){
    bool * visited=new bool[n]{0};
    int * arr=new int[n]{-1};
    bool res;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[0]=1;
            res=bfs(i,g,n,-1,&arr,&visited);
            if(res){
                delete [] arr;
                delete [] visited;                
                return res;
            }
        }
    }
    delete [] arr;
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