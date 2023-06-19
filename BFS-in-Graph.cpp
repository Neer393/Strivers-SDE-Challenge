#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges){
    vector<bool>visited(vertex,false);
    vector<vector<int>>adj(vertex);
    for(auto edge:edges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    for(int i=0;i<vertex;i++)   sort(adj[i].begin(),adj[i].end());
    vector<int>ans;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto neighbour:adj[node]){
                    if(!visited[neighbour]){ 
                        q.push(neighbour);
                        visited[neighbour]=true;
                    }
                }
            }
        }
    }
    return ans;
}
