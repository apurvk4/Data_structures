#include<iostream>
#include<vector>
#include<unordered_set>
int spanningTree(int V, int e, std::vector<std::vector<int>> &g) {
    int key[V],res=0;
    std::fill(key,key+V,INT32_MAX);
    key[0]=0;
    bool mset[V]={0};
    for(int count=0;count<V;count++){
        int u=-1;
        for(int i=0;i<V;i++){
            if(!mset[i] && (u==-1 || key[i]<key[u])){
                u=i;
            }
        }
        mset[u]=true;
        res+=key[u];
        for(int v=0;v<V;v++){
            if(g[u][v] !=INT32_MAX && !mset[v]){
                key[v]=std::min(key[v],g[u][v]);
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
   
   std::cout<<spanningTree(v,e,g)<<"\n";
   return 0;
}