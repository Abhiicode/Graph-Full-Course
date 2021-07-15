#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int>&vis, vector<int>&low, vector<int>&tin, vector<int>&ap
,vector<int>adj[],int&timer){
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent)continue;
            if(!vis[it]){
                dfs(it,node,vis,low,tin,ap,adj,timer);
                low[node] = min(low[node],low[it]);
                if(low[it]>=tin[node] && parent != -1){
                    ap[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child>1 && parent == -1){  //it's the case where your first node contains independent childs so
                                      //your first node is one of the point as well
            ap[node] = 1;
        }
}



int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0 ; i<m ; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>tin(n,0);
    vector<int>low(n,0);
    int timer = 0;
    vector<int>articulationPoints(n,0);
    for(int i =0 ; i<n ; i++){
        if(!vis[i]){
            dfs(i,-1,vis,low,tin,articulationPoints,adj,timer);
        }
    }

    for(int i = 0 ; i<n ; i++){
        if(articulationPoints[i]==1){
            cout<<"this is our articulation point "<<i<<endl;   
        }
    }
}