#include <bits/stdc++.h> 

void solve(int r,int c,vector<vector<int> > &maze,int &n,vector<vector<bool>>&vis,vector<vector<int>>&ans){
  if(r==n-1 && c==n-1){
    int ogval = maze[r][c];
    maze[r][c]=2;
    vis[r][c]=true;
    vector<int>temp;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(maze[i][j]==2) temp.push_back(1);
        else  temp.push_back(0);
      }
    }
    ans.push_back(temp);
    maze[r][c]=ogval;
    vis[r][c]=false;
    return;
  }
  int ogval = maze[r][c];
  maze[r][c]=2;
  vis[r][c]=true;

  //UPWARD
  if(r!=0 && maze[r-1][c]==1 && !vis[r-1][c]){
    solve(r-1,c,maze,n,vis,ans);
  }

  //DOWNWARD
  if(r!=n-1 && maze[r+1][c]==1 && !vis[r+1][c]){
    solve(r+1,c,maze,n,vis,ans);
  }

  //LEFT
  if(c!=0 && maze[r][c-1]==1 && !vis[r][c-1]){
    solve(r,c-1,maze,n,vis,ans);
  }

  //RIGHT
  if(c!=n-1 && maze[r][c+1]==1 && !vis[r][c+1]){
    solve(r,c+1,maze,n,vis,ans);
  }

  maze[r][c]=ogval;
  vis[r][c]=false;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> ans;
  if(maze[0][0]==0 || maze[n-1][n-1]==0)  return ans;
  vector<vector<bool>>vis(n,vector<bool>(n,false));
  solve(0,0,maze,n,vis,ans);
  return ans;
}
