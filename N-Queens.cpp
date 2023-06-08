#include<bits/stdc++.h>

bool isSafe(int r,int col,vector<vector<int>>&board,int n){
    int x=r,y = col;
    while(x>=0){
        if(board[x][col]==1)  return false;
        x--;
    }
    x=r;
    while(x>=0 && y>=0){
        if(board[x][y]==1)  return false;
        x--;
        y--;
    }
    x=r,y=col;
    while(x>=0 && y<n){
        if(board[x][y]==1)  return false;
        x--;
        y++;
    }
    return true;
}

bool nQueen(int r,int n,vector<vector<int>>&board,vector<vector<int>>&ans){
    if(r>=n){
        
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(r,col,board,n)){
            board[r][col]=1;
            if(nQueen(r+1,n,board,ans)){
                vector<int>temp;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        temp.push_back(board[i][j]);
                    }
                }
                ans.push_back(temp);
            }
            board[r][col]=0;
        }
    }
    return false;
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    if(n==2 || n==3)    return ans;
    if(n==1){
        ans.push_back({1});
        return ans;
    }
    vector<vector<int>> board(n,vector<int>(n,0));
    nQueen(0,n,board,ans);
    return ans;
}
