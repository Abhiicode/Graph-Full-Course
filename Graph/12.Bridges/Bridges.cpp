#include<bits/stdc++.h>
using namespace std;
void dfs(int node , int parent , vector<int>adj[], vector<int>&vis,vector<int>&low,vector<int>&tin,int&timer){
    vis[node] = 1;
    low[node] = tin[node] = timer++;
    for(auto it : adj[node]){
        if(it == parent)continue;
        if(!vis[it]){
            dfs(it,node,adj,vis,low,tin,timer);
            low[node] = min(low[node], low[it]);   //you need to calculate the minimum low time amonge it's adjacents
            if(low[it]>tin[node]){   // even after removing of node you can reach at that node and before that node
                cout<<"this is the bridge "<<it<<" to "<<node<<endl;
            }
        }else{
            low[node] = min(low[node], tin[it]);   
        }
    }
}

int main(){

   int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, adj, vis, low, tin, timer); 
	    }
	}
	
	return 0;

}