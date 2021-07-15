#include<bits/stdc++.h>
using namespace std;

void getShortestDistance(int source, int n , vector<int>adj[]){
        vector<int>distArray(n,INT_MAX);
        distArray[source] = 0;
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(distArray[node]+1 < distArray[it]){
                    distArray[it] = distArray[node]+1;
                    q.push(it);
                }
            }
        }

        for(int i = 0 ; i<n ; i++){
            cout<<"the distance from "<<source<<" to the node "<<i<<" is "<<distArray[i]<<" ";
        }
}