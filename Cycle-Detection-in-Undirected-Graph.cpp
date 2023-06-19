bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour,node,adj,visited)) return true;
        }
        else if(neighbour!=parent)  return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector<bool>visited(n+1,false);
    vector<vector<int>> adj(n+1);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited))   return "Yes";
        }
    }
    return "No";
}
