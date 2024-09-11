#include <bits/stdc++.h>
#include <queue>
using namespace std;

// using this function you can find weight of minimum spanning tree(MST)
int prims_1(int n, vector<vector<pair<int,int>>>&adj){
    vector<bool>visi(n);
    int sum = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,0});

    while(!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        if(visi[node]) continue;
        sum+=wt;
        visi[node]=true;
        for(auto el : adj[node]){
            int adjNode = el.first;
            int adjWT = el.second;
            if(visi[adjNode]==false) pq.push({adjWT,adjNode});
        }
    }
    return sum;
}

// This function will return list all edges of minimum spanning tree
vector<pair<int,int>> prims_2(int n, vector<vector<pair<int,int>>>&adj){
    vector<bool>visi(n);
    int sum = 0;
    vector<pair<int,int>>ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0,0,-1});

    while(!pq.empty()){
        int node = pq.top()[1];
        int wt = pq.top()[0];
        int pare = pq.top()[2];

        if(pare==-1){
            visi[node]=true;
        }
        else if(visi[node]) continue;
        visi[node]=true;
        if(pare!=-1)
            ans.push_back({pare,node});
        sum+=wt;
        for(auto el : adj[node]){
            int adjNode = el.first;
            int adjWT = el.second;
            if(visi[adjNode]==false) pq.push({adjWT,adjNode,node});
        }
    }
    return ans;
}
