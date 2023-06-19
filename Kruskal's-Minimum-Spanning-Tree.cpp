#include <bits/stdc++.h> 

void make_pair(int v,vector<int>&parent){
	for(int i=1;i<=v;i++){
		parent[i]=i;
	}
}

int find_parent(int v,vector<int>&parent){
	if(v==parent[v])	return v;
	return parent[v]= find_parent(parent[v],parent);
}

void union_set(int u,int v,vector<int>&parent,vector<int>&size){
	u = find_parent(u,parent);
	v = find_parent(v,parent);
	if(u!=v){
		if(size[u]<size[v]){
			parent[u]=v;
			size[v]+=size[u];
		}
		else{
			parent[v]=u;
			size[u]+=size[v];
		}
	}
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<int>parent(n+1),size(n+1,1);
	make_pair(n,parent);
	sort(graph.begin(),graph.end(),[&](vector<int>&a,vector<int>&b){
		return a[2]<b[2];
	});
	int cost = 0;
	for(int i=0;i<m;i++){
		int u = find_parent(graph[i][0],parent);
		int v = find_parent(graph[i][1],parent);
		if(u!=v){
			cost+=graph[i][2];
			union_set(u,v,parent,size);
		}
	}
	return cost;
}
