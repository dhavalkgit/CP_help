void topSort(vector<vector<int>>&adj, vector<bool>&visi, int node, stack<int>&st){
    visi[node]=true;

    for(auto el:adj[node]){
        if(!visi[el]){
            topSort(adj,visi,el,st);
        }
    }

    st.push(node);
}

/**
    for(i ->n){
        if(!visi[i]){
            topSort(i,adj,visi,st);
        }
    }

    vector<int>ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
*/
