void dfs(int r,int c,int n,int m,vector<vector<bool>>&visited,int **arr){
   visited[r][c]=true;
   for(int i=-1;i<=1;i++){
      for(int j=-1;j<=1;j++){
         if(i==0 && j==0)  continue;
         int nr=r+i;
         int nc=c+j;
         if(nr>=0 && nr<n &&nc>=0 && nc<m && !visited[nr][nc] && arr[nr][nc]==1){
            dfs(nr,nc,n,m,visited,arr);
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<bool>>visited(n,vector<bool>(m,false));
   int cnt=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(!visited[i][j] && arr[i][j]==1){
            cnt++;
            dfs(i,j,n,m,visited,arr);
         }
      }
   }
   return cnt;
}
