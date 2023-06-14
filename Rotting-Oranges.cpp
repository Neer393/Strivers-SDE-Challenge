#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,int>>q;
    int delrow[]={-1,0,0,1};
    int delcol[]={0,-1,1,0};
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)   q.push({i,j});
            if(grid[i][j]==1)   count++;
        }
    }
    if(count==0)    return 0;
    int cnt=0;
    while(!q.empty()){
        int sz=q.size();
        cnt++;
        for(int i=0;i<sz;i++){
            auto x = q.front();
            q.pop();
            int r = x.first;
            int c = x.second;
            for(int j=0;j<4;j++){
                int nr=r+delrow[j];
                int nc=c+delcol[j];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)   return -1;
        }
    }
    return cnt-1;
}
