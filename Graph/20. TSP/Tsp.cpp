	#include<bits/stdc++.h>
	using namespace std;
   void dfs(  int sPos,int Node , int adj[][4], vector<int>&vis, int count , int &n , int currentSum, 
int &minCost){
		vis[Node] = 1;
		count++;
      if(count == n && adj[Node][sPos]){
		  minCost = min(minCost, currentSum + adj[Node][sPos]);
	  }

	  for(int v = 0 ; v<n ; v++){
		  if(adj[Node][v] && !vis[v]){
			  dfs(sPos,v,adj,vis,count,n,currentSum+adj[Node][v],minCost);
		  }
	  }
	  vis[Node] = 0;
}

int main(){
	int matrix[4][4];
	int edges = 6;
	int V = 4;
	int u , v,wt;
	for(int i = 0 ; i<edges; i++){
		cin>>u>>v>>wt;
		matrix[u][v] = wt;
		matrix[v][u] = wt;
	}
	vector<int>vis(V,0);
	int minCost = INT_MAX;
	dfs(0,0,matrix,vis,0,V,0,minCost);
	cout<<minCost;
}
