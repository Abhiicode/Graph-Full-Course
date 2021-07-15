#include<bits/stdc++.h>
using namespace std;

//DFS Technique to traverse all the nodes in an graph

// we will use recursion/stack but not queue as we did before in bfs 

void dfs(int node , vector<int>adj[], vector<int>&vis , vector<int>&res){
            vis[node] = 1;
            res.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){   
                    dfs(it,adj,vis,res);
                }
            }
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

    vector<int>res;
    vector<int>visited(n+1,0);
    for(int i = 1 ; i<=n ; i++){
        if(!visited[i]){
            dfs(i,adj,visited,res);
        }
    }
    // at this point you will get your result array with all nodes ;) 
}