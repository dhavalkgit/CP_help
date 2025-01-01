#include<bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(int node, int parent, int tin[], int low[], vector<bool> &visi, vector<bool> &marked, vector<int> adj[])
{
    visi[node] = true;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!visi[it])
        {
            dfs(it, node, tin, low, visi, marked, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1)
                marked[node] = true;
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (parent == -1 && child > 1)
        marked[node] = true;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    int tin[V];
    int low[V];
    vector<bool> visi(V, false);
    vector<bool> marked(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visi[i])
            dfs(i, -1, tin, low, visi, marked, adj);
    }
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (marked[i])
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}