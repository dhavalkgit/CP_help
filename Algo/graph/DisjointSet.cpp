class DisjointSet{
    vector<int>rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }

        int findUPare(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPare(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u=findUPare(u);
            int ulp_v=findUPare(v);

            if(ulp_u==ulp_v) return ;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }

        bool inSameComponent(int u, int v){
            return parent[u]==parent[v];
        }
};
