#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    vector<int>adj[n+1];
    // this is the input format for undirected Graph / biDirectional Graph
    // if there is an edge b/w 1 -> 2 then there is also be a edge b/w 2 -> 1 in bidirectional graph
    for(int i = 0 ; i<e;i++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //this is the input format for directed Graph / Directional Graph
    //there will be a single road edge b/w nodes/vertices of graph

    for(int i = 0 ;i<e ;i++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }


    // Weighted Graphs
    // for these type of graphs you need to create an array of vector<pair<int,int>>

    vector<pair<int,int>>weightedGraph[n+1];
    for(int i = 0 ; i<e;i++){
        int u , v , w;
        cin>>u>>v>>w;
        weightedGraph[u].push_back({v,w});
        weightedGraph[v].push_back({u,w});
    }   
}