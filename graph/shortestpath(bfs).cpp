#include<iostream>
#include<vector>
#include<queue>
int shortestPath(int src,int dest,std::vector<int> g[],int n){
    if(src==dest){return 0;}
    std::queue<int> q;
    bool visited[n]={0};
    q.push(src);
    visited[src]=1;
    int count=0;
    int size=INT32_MAX;
    int res=INT32_MAX;
    while(!q.empty()){
        int a=q.size();
        for(int i=0;i<g[q.front()].size();i++){
            if(q.front()==dest){continue;}
            if(g[q.front()][i]==dest){
                if(size==INT32_MAX){
                    res=std::min(res,count+1);
                }else{
                    res=std::min(res,count+2);
                }
                q.push(dest);
                continue;
            }
            if(visited[g[q.front()][i]]==0){
                q.push(g[q.front()][i]);
                visited[g[q.front()][i]]=1;
            }
        }
        if(size==INT32_MAX){
            size=q.size()-a+1;
        }
        if(size>1){
           size--;
           q.pop();
        }else{
            count++;
            size=q.size()-a+1;
            q.pop();
        }
    }
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
   int src,dest;
   std::cin>>src>>dest;
   std::cout<<"minimum distance is : "<<shortestPath(src,dest,g,v)<<std::endl;
   return 0;
}