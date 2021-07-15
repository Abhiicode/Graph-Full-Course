#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int>adj[], vector<int>&vis, vector<int>&dfsVis){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycle(it,adj,vis,dfsVis))return true;
        }
        else if(dfsVis[it])return true;           // if both visited and dfsVisited index is true for a 
    }                                            //particular node that means there are a cycle becase it's 
    dfsVis[node] = 0;                           //consist of two ways to come there in a single route(rotation)
    return false;
}

bool isCylic(int n , vector<int>adj[]){
    vector<int>vis(n,0);
    vector<int>dfsVis(n,0);
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            if(checkCycle(i , adj, vis,dfsVis))return true;
        }
    }
    return false;
}
int main(){
    int i = 10,20,30;
  printf("%d", i); 
}