#include <bits/stdc++.h> 

bool isSafeToColor(int idx,int color,int &n,int &m,vector<int>&node_colors,vector<vector<int>> &mat){
    for(int i=0;i<n;i++){
        if(i==idx)  continue;
        if(mat[idx][i]==1 && node_colors[i]==color) return false;
    }
    return true;
}

bool solve(int idx,int &n,int &m,vector<int>&node_colors,vector<vector<int>> &mat){
    if(idx>=n)  return true;
    for(int col = 1;col<=m;col++){
        if(isSafeToColor(idx,col,n,m,node_colors,mat)){
            node_colors[idx]=col;
            if(solve(idx+1,n,m,node_colors,mat)){
                return true;
            }
            node_colors[idx]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int> node_colors(n,0);
    if(solve(0,n,m,node_colors,mat)){
        return "YES";
    }
    return "NO";
}
