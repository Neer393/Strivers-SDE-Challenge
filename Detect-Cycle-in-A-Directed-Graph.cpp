bool dfs(int node,vector<bool>&visited,vector<bool>&dfsvisited,vector<vector<int>>&adj){
  visited[node]=true;
  dfsvisited[node]=true;
  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      if(dfs(neighbour,visited,dfsvisited,adj)) return true;
    }
    else if(dfsvisited[neighbour])  return true;
  }
  dfsvisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<bool>visited(n+1,false),dfsvisited(n+1,false);
  vector<vector<int>>adj(n+1);
  for(auto edge:edges)  adj[edge.first].push_back(edge.second);
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      if(dfs(i,visited,dfsvisited,adj)) return 1;
    }
  }
  return 0;
}
