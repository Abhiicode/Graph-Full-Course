#include<bits/stdc++.h>
using namespace std;
// this algo is also known as Kahn's Algo
vector<int>topoSortBFS(int n , vector<int>adj[]){
    vector<int>res;
    vector<int>inDegree(n,0);
    for(int i = 0 ; i<n ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int>q;
    for(int i = 0 ; i< n ; i++){
        if(inDegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        res.push_back(node);
        q.pop();
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }
    return res;

}