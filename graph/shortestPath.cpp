#include<iostream>
#include<vector>
/*
find shortest path from a single source in a weighted directed acyclic graph(DAG). 
*/
struct edge{
    int v;
    int weight;
    edge(int _v,int w):v{_v},weight{w}{
    }
};
void solve(int i,std::vector<edge> g[],int n,std::vector<int> & out,int **a,bool **visit){
    if(i>=out.size()){return;}
    int *arr=*a;
    bool *v=*visit;
    for(int j=0;j<g[out[i]].size();j++){
        arr[g[out[i]][j].v]--;
        if(arr[g[out[i]][j].v]==0){
            if(v[g[out[i]][j].v]==0){
                out.push_back(g[out[i]][j].v);
                v[g[out[i]][j].v]=1;
            }
        }
    }
    solve(++i,g,n,out,a,visit);
}
std::vector<int> topologicalSorting(std::vector<edge> g[],int n){
    std::vector<int> out;
    bool * visited=new bool[n]{0};
    int * a=new int[n]{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            a[g[i][j].v]++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(visited[i]==0){
                out.push_back(i);
                visited[i]=1;
            }
        }
    }
    solve(0,g,n,out,&a,&visited);
    delete [] a;
    delete [] visited;
    return out;
}
std::vector<int> shortestPath(std::vector<edge> g[],int n){
    std::vector<int> topo=topologicalSorting(g,n);
    std::vector<int> res;
    std::vector<int> a(n,INT32_MAX);
    a[topo[0]]=0;
    for(int i=0;i<topo.size();i++){
        for(int j=0;j<g[topo[i]].size();j++){
            if(a[g[topo[i]][j].v]>a[topo[i]]+g[topo[i]][j].weight){
               a[g[topo[i]][j].v]=a[topo[i]]+g[topo[i]][j].weight;
            }
        }
    }
    return a;
}
int main(){
   int v,e;
   std::cout<<"Enter number of vertex and number of edges : ";
   std::cin>>v>>e;
   std::vector<edge> g[v];
   std::cout<<"Enter adjacent list of the graph "<<std::endl;
   for(int i=0;i<e;i++){ 
      int u,v1,w;
      std::cin>>u>>v1>>w;
      edge *e=new edge(v1,w);
      g[u].push_back(*e);
   }
   for(auto val : shortestPath(g,v)){
       std::cout<<val<<" ";
   }
   std::cout<<"\n";
   return 0;
}