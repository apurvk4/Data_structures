#include<iostream>
#include "graph.hpp"

int main(){

    graph<int,undirected> g;
    try{
        g.insertVertex(13);
        g.insertVertex(34);
        auto it=g.begin();
        it++;
        g.connectEdge(g.begin(),it);
        g.insertVertex(56);
        it++;
        g.connectEdge(g.begin(),it);
        auto it1=g.begin();
        it1++;
        g.connectEdge(it,it1);
        it.moveTo(g.begin());
        it++;
        it.moveTo(g.begin());
        for(;it !=g.end();it++){
            std::cout<<it<<" ";
            if(g.hasEdges(it)){
                for(auto e_id=g.Edge_begin(it);e_id !=g.Edge_end();e_id++){
                    std::cout<<e_id<<" ";
                }
                std::cout<<"\n";
            }else{
                std::cout<<"No Edges"<<"\n";
            }
        }
    }catch(Invalid_traverse & e){
        std::cerr<<"Error : "<<e.what()<<"\n";
    }
    return 0;
}