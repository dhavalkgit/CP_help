#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj,
         vector<vector<int>> &bridge, vector<bool> &visi)
{
    visi[node] = true;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!visi[it])
        {
            dfs(it, node, tin, low, adj, bridge, visi);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                bridge.push_back({node, it});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    vector<bool> visi(n, false);
    vector<vector<int>> bridge;

    for (auto edge : connections)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1, tin, low, adj, bridge, visi);

    return bridge;
}