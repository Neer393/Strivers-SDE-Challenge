#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    vector<int>up(m,0);
    up[0]=grid[0][0];
    for(int i=1;i<m;i++)
        up[i]=up[i-1]+grid[0][i];
    for(int i=1;i<n;i++){
        vector<int>temp(m,1e9);
        int prev=1e9;
        for(int j=0;j<m;j++)
            temp[j]=prev=min(prev,up[j])+grid[i][j];
        up=temp;
    }
    return up[m-1];
}
