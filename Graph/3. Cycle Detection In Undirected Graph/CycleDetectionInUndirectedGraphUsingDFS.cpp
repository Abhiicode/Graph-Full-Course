#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>adj[], vector<int>&vis , int node, int parent ){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(adj,vis,it,node))return true;
        }
        else if(it!=parent)return true;
    }
    return false;
}
int main(){


    int n , e;
    cin>>n>>e;
    vector<int>adj[n+1];
    // this is the input format for undirected Graph / biDirectional Graph
    // if there is an edge b/w 1 -> 2 then there is also be a edge b/w 2 -> 1 in bidirectional graph
    for(int i = 0 ; i<e;i++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    for(int i = 1 ; i<=n ; i++){
        if(!visited[i]){
            if(dfs(adj,visited,i,-1))return true;
        }
    }
    return false;
}