#include<bits/stdc++.h>
using namespace std;

//BFS Traversal Technique

// so you will use a queue here and keep adding the adjacent nodes until all the nodes get visited

vector<int>bfsOfGraph(int v , vector<int>adj[]){
    vector<int>res;
    vector<int>visited(v+1,0);
     queue<int>q;
    for(int i = 1 ;i<=v ; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                res.push_back(node);

                for(auto it : adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    // here is the end of BFS Traversal.
}