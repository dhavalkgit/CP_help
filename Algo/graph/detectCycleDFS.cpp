bool iscycle(vector<vector<int>>&adj, vector<bool>&visi, vector<bool>&dfs,int node){
    visi[node]=true;
    dfs[node]=true;

    for(auto el:adj[node]){
        if(!visi[el]){
            bool ans = iscycle(adj,visi,dfs,el);
            if(ans) return true;
        }
        else if(dfs[el]) return true;
    }
    
    dfs[node]=false;
    return false;
}
