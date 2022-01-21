#include<iostream>
#include<vector>

std::vector<int> DjkShortestPath(int src,int V, int e, std::vector<std::vector<int>> &g) {
    std::vector<int> res(V,0);
    int key[V];
    std::fill(key,key+V,INT32_MAX);
    key[src]=0;
    bool mst[V]={0};
    int source[V]={0};
    for(int i=0;i<V;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(!mst[j] && (u==-1 || res[source[j]]+key[j]<res[source[u]]+key[u])){
                u=j;
            }
        }
        mst[u]=1;
        if(u != src){
            res[u]=res[source[u]]+key[u];
        }else{
            res[u]=0;
        }
        for(int j=0;j<V;j++){
            if(g[u][j] !=0 && !mst[j]){
                if(key[j]==INT32_MAX){
                    source[j]=u;
                    key[j]=g[u][j];
                }else if(key[j] !=INT32_MAX && (res[u]+g[u][j]<key[j]+res[source[j]])){
                    source[j]=u;
                    key[j]=g[u][j];
                }    
            }
        }
    }
    return res;
}
int main(){
   int v,e;
   std::cout<<"Enter number of vertex and number of edges : ";
   std::cin>>v>>e;
   std::vector<int> E1(e,INT32_MAX);
   std::vector<std::vector<int>> g(v,E1);
   std::cout<<"Enter adjacent list of the graph "<<std::endl;
   for(int i=0;i<e;i++){ 
      int u,v1,w;
      std::cin>>u>>v1>>w;
      g[v1][u]=w;
      g[u][v1]=w;
   }
   for(auto val : DjkShortestPath(0,v,e,g)){
       std::cout<<val<<" "; 
   }
   std::cout<<"\n";
   return 0;
}