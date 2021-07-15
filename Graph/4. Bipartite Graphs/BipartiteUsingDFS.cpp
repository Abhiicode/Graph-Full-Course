#include<bits/stdc++.h>
using namespace std;

// concept is simple and crisp if the color of parent and it's child matches that graph can't be bipartite

bool dfsBipartite(vector<int>adj[], int node , vector<int>&color){
    if(color[node]==-1)color[node] = 1;
    for(auto it : adj[node]){
        if(color[it]==-1){
            color[it] = 1 - color[node];
            if(!dfsBipartite(adj,it,color))return false;
        }
        else if(color[it] == color[node])return false;
    }
    return true;
}