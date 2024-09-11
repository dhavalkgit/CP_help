vector<int> dijkstra(int n , int s, vector<vector<pair<int,int>>>&adj){
    vector<int>dist(n, INT_MAX);
    dist[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,s});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto el : adj[node]){
            int edgWeight = el.second;
            int adjNode = el.first;

            if((dis+edgWeight)<dist[adjNode]){
                dist[adjNode]=dis+edgWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
