#include<iostream>
#include<vector>
void solve(int i,std::vector<int> g[],int n,std::vector<int> & out,int **a,bool **visit){
    if(i>=out.size()){return;}
    int *arr=*a;
    bool *v=*visit;
    for(int j=0;j<g[out[i]].size();j++){
        arr[g[out[i]][j]]--;
        if(arr[g[out[i]][j]]==0){
            if(v[g[out[i]][j]]==0){
                out.push_back(g[out[i]][j]);
                v[g[out[i]][j]]=1;
            }
        }
    }
    solve(++i,g,n,out,a,visit);
}
std::vector<int> topologicalSorting(std::vector<int> g[],int n){
    std::vector<int> out;
    bool * visited=new bool[n]{0};
    int * a=new int[n]{0};
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            a[g[i][j]]++;
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
   for(auto val:topologicalSorting(g,v)){
       std::cout<<val<<" ";
   }
   std::cout<<"\n";
   return 0;
}