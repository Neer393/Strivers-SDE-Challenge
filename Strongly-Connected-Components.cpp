#include<bits/stdc++.h>

void toposort(int node,vector<bool>&vis,stack<int>&st,vector<int> adj[]){
    vis[node]=true;
    for(auto neighbour: adj[node]){
        if(!vis[neighbour]){
            toposort(neighbour,vis,st,adj);
        }
    }
    st.push(node);
}

void dfs(int node,vector<bool>&vis,vector<int>newadj[],vector<int>&temp){
    vis[node]=true;
    temp.push_back(node);
    for(auto neighbour: newadj[node]){
        if(!vis[neighbour]){
            dfs(neighbour,vis,newadj,temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<int> adj[n],newadj[n];
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        newadj[i[1]].push_back(i[0]);
    }
    vector<bool> vis(n,false);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,vis,st,adj);
        }
    }
    vis = vector<bool>(n,false);
    vector<vector<int>> ans;
    vector<int>temp;
    while(!st.empty()){
        auto topnode = st.top();
        st.pop();
        if(!vis[topnode]){
            dfs(topnode,vis,newadj,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
    }
    return ans;

}
