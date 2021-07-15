#include<bits/stdc++.h>
using namespace std;


bool bfsBipartite(vector<int>adj[], int node , vector<int>&color){
    queue<int>q;
    q.push(node);
    color[node] = 1;
    while(!q.empty()){
        int pNode = q.front();
        q.pop();
        for(auto it : adj[pNode]){
            if(color[it] == -1){
                color[it] = 1 - color[pNode];
                q.push(it);
            }else if(color[it] == color[pNode])return false;
        }
    }
    return true;
}