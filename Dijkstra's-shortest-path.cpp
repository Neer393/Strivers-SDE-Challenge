#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>>adjlist;
    for(auto i:vec){
        int u=i[0];
        int v=i[1];
        int w=i[2];
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;
    set<pair<int,int>>s;
    s.insert({0,source});
    while(!s.empty()){
        auto topval = *(s.begin());
        int currdist = topval.first;
        int currnode = topval.second;
        s.erase(s.begin());
        for(auto neighbour:adjlist[currnode]){
            int v = neighbour.first;
            int w=neighbour.second;
            if(currdist + w < dist[v]){
               s.erase({dist[v],v});
                dist[v]=currdist+w;
                s.insert({dist[v],v});
            }
        }
    }
    return dist;
}
