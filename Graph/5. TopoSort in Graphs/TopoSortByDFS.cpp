#include<bits/stdc++.h>
using namespace std;

void TopoSortDFS(int node , vector<int>&vis , stack<int>&st , vector<int>adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                TopoSortDFS(it,vis,st,adj);   
            }
        }
        st.push(node);
}

vector<int>solve(int n , vector<int>adj[]){
         stack<int>st;
         vector<int>vis(n,0);
         for(int i = 0 ;i<n ; i++){
             if(!vis[i]){
                 TopoSortDFS(i,vis,st,adj);
             }
         }

         vector<int>res;
         while(!st.empty()){
             res.push_back(st.top());
             st.pop();
         }
         return res;
}