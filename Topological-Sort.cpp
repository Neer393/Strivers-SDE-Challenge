#include <bits/stdc++.h> 

void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj,stack<int>&st){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,visited,adj,st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    stack<int>st;
    vector<bool>visited(v,false);
    vector<vector<int>>adj(v);
    for(auto edge:edges)    adj[edge[0]].push_back(edge[1]);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
