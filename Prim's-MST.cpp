#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adjlist;
    for(auto i:g){
        int u=i.first.first;
        int v=i.first.second;
        int w=i.second;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<=n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(!mst[j] && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }
        mst[u]=true;
        for(auto neighbour:adjlist[u]){
            int v= neighbour.first;
            int w=neighbour.second;
            if(!mst[v]&&w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{i,parent[i]},key[i]});
    }
    return ans;
}
