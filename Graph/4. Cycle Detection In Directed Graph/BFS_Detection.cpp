#include<bits/stdc++.h>
using namespace std;
// this algo is also known as Kahn's Algo
bool topoSortBFS(int n , vector<int>adj[]){
    vector<int>res;
    vector<int>inDegree(n,0);
    for(int i = 0 ; i<n ; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }
// if the graph is DAG -> directed Acyclic Graph which means no cycle there would be a topo sort 
    queue<int>q;
    for(int i = 0 ; i< n ; i++){
        if(inDegree[i]==0)q.push(i);
    }
    int count  = 0;
// hence if number of nodes in topo sort == number of vertices that means no cycle becasuse topo sort generated
// else there would be a cycle in our graph
    while(!q.empty()){
        int node = q.front();
        count++;
        q.pop();
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }
    if(count == n)return false;
    return true;

}