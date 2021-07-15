#include<bits/stdc++.h>
using namespace std;
/* steps to find the shortest path in directed acyclic Graph is here :-
1 . find the topological sort for the following graph either by dfs or bfs I prefer dfs for shorter code
2. now maintain a distance array with INT_MAX for each node initially
3. mark the distanc[source] = 0 cuz distance from source to source is 0 obv
4. now check for it's adjacent nodes in a graph if the distance[child] > edgeWeight b/w node and child
   + distance[node] replace it because we need to find minimum right
5. now do the same thing for the next node but keep a check call on a node only if distance[node]!=INT_MAX
   because this means there is no path b/w source to that node. */

   // finding TopoLogical Sort

   void TopoSortDFS(int node , vector<int>&vis , stack<int>&st , vector<pair<int,int>>adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                TopoSortDFS(it.first,vis,st,adj);
            }
        }
        st.push(node);
}
// using topo sort stack to get our answer
void solve(int n , vector<pair<int,int>>adj[], int source){
         stack<int>st;
         vector<int>vis(n,0);
         for(int i = 0 ;i<n ; i++){
             if(!vis[i]){
                 TopoSortDFS(i,vis,st,adj);
             }
         }

         vector<int>distance(n,1e7);
         distance[source] = 0;

         while(!st.empty()){
             int node = st.top();
             st.pop();
             if(distance[node]!=1e7){
                 for(auto it : adj[node]){
                     if(it.second + distance[node] < distance[it.first]){
                         distance[it.first] = it.second + distance[node];
                     }
                 }
             }
         }

         // at this point you have your distance array with minimum distance b/w source to any node
         // and once again if any where in distance array you would find 1e7 that means there is no path b/w 
         // source to that node
}

