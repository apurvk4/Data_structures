#include<iostream>
#include<vector>
/*
find shortest path in an unweighted graph.
*/
struct visited{
    bool v;
    int src;
    int dest;
    visited():v{0},src{INT32_MIN},dest{INT32_MIN}{
    }
};
void setvisit(bool val,int src,int dest,visited & obj){
    obj.src=src;
    obj.v=val;
    obj.dest=dest;
}
bool check(visited & obj,int src,int dest,visited * v){
    if(obj.v){
        if(obj.src !=src && obj.dest==dest){
            visited v1=v[src];
            if(v1.src==dest && v1.dest==src && v1.v){
                return false;
            }else{return true;}
        }else if(obj.src==INT32_MIN && obj.dest==INT32_MIN){
            return true;
        }else{
            return false;
        }
    }else{
        return true;
    }
}
void Dfs(int src,int & res,int dest,std::vector<int> g[],visited ** visit,int count){
    visited *v=*visit;
    for(int i=0;i<g[src].size();i++){
        if(check(v[g[src][i]],src,g[src][i],v)){
            if(g[src][i]==dest){
                res=std::min(res,count+1);
                return;
            }else{
                setvisit(1,src,g[src][i],v[g[src][i]]);
            }
            Dfs(g[src][i],res,dest,g,visit,count+1);
        }
    }
}
int shortestPath(int src,int dest,std::vector<int> g[],int n){
    if(src==dest){return 0;}
    visited * visit=new visited[n];
    setvisit(1,src,INT32_MIN,visit[src]);
    int res=INT32_MAX;
    Dfs(src,res,dest,g,&visit,0);
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
/*
1. you cannot go to source again from any other edge i.e you can never travel from any other edge towards source edge.
2. if there are two edge A & B with B !=destination_edge with an undirected edge connecting them
 i.e A------B then 
 a. if we travelled through A to B then 
    a1. we cannot travel from B to A using same edge.
    a2. we can always travel from A to B again using same edge if we again somehow land at edge A.
3.  you can travel directly towards destinaton any number of times from any edge i.e A-----dest.
    then you can travel towards destination from A again an again using same edge. 
*/