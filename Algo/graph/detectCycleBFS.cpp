bool detectCycle(int src, bool visi[], vector<vector<int>>adj){
    queue<pair<int,int>>q;
    q.push({src,-1});
    visi[src]=true;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto el : adj[node]){
            if(!visi[el]){
                q.push({el,node});
                visi[el]=true;
            }
            else if(el != parent){
                return true;
            }
        }
    }
    return false;
}

