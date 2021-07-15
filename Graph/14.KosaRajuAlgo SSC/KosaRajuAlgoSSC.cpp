//Three steps involved in this algo
// Find the toposort so you can call dfs later on time wisely
// Create an transpose for the same graph
// Now the last step make sure to call dfs on transpose graph acc to topo sort

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[], stack<int>&s, vector<int>&vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            dfs(it,adj,s,vis);
        }
        s.push(node);
}
void reVisDFS(int node, vector<int>&vis, vector<int>transpose[]){
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it : transpose[node]){
        if(!vis[it]){
            reVisDFS(it, vis,transpose);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0; i < m ; i++){
        int u,v,w;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>vis(n,0);
    stack<int>s;

    //STEP 1 FINDING THE TOPO SORT
    for(int i = 0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i,adj,s,vis);
        }
    }

    //STEP 2 CREATING AN TRANSPOSE OF THAT DIRECTED GRAPH
    vector<int>transpose[n];

    for(int i = 0 ; i<n ; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }

    //NOW CALL DFS ACCORDING TO THE TOPOSORT IN A GRAPH
    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout<<"SSC is : ";
        reVisDFS(node,vis,transpose);
        cout<<endl;
    }
return 0;
}