int parent[100000];
int rank[100000];

void makeSet(int n){
    for(int i = 1 ; i<=n ; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node){
    if(node==parent[node])return node;
    return parent[node] = findPar(parent[node]);
}

void unioon(int u , int v){
    u = findPar(u);
    v = findPar(v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[u]>rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}
int main(){
    int n;
    makeSet(n);

    // T.c (4 Alpha)
}