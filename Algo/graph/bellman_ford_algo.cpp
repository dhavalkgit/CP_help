vector<int> bellman(int n, int s, vector<vector<int>>&edges){
    vector<int>dist(n,INT_MAX);
    dist[s]=0;
    for(int i=1;i<n;i++){
        for(auto el : edges){
            int u = el[0];
            int v = el[1];
            int wt = el[2];
            if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }

    // to detect negative weight cycle iterate all edges one more time

    for(auto el : edges){
        int u = el[0];
        int v = el[1];
        int wt = el[2];
        if(dist[u]!= INT_MAX && dist[u]+wt < dist[v]){
            return {-1}; // cycle is present 
        }
    }
    return dist;    
}
