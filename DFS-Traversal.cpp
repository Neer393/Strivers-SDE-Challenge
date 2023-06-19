void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj,vector<int>&temp){
    visited[node]=true;
    temp.push_back(node);
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,visited,adj,temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>ans;
    vector<vector<int>> adj(V);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>temp;
            dfs(i,visited,adj,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
