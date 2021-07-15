#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
// this algo work for any kind of graph 

int main(){
    vector<vector<int>> graph = {
                                    {0,5,INF,10},
                                    {INF,0,3,INF},
                                    {INF,INF,0,1},
                                    {INF,INF,INF,0},
                                };

    int n = graph.size();
    //T.C = o(n^3)
    auto dist = graph;
// checking all the other routes for every possible pairs ;) 

    for(int k  = 0 ; k<n ; k++){
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(dist[i][k] + dist[k][j]< dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
// printing graph
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<n ; j++){
            cout<<dist[i][j]<<" "<<endl;
        }
    }
}