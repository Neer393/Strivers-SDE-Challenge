void dfs(vector<vector<int>> &image,int n,int m, int x, int y,int ogcolor, int newColor,int delrow[],int delcol[]){
    image[x][y]=newColor;
    for(int i=0;i<4;i++){
        int nr = x+delrow[i];
        int nc = y+delcol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==ogcolor){
            dfs(image,n,m,nr,nc,ogcolor,newColor,delrow,delcol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    if(image[x][y]==newColor)   return image;
    int n=image.size();
    int m=image[0].size();
    int delrow[]={-1,0,0,1};
    int delcol[]={0,-1,1,0};
    dfs(image,n,m,x,y,image[x][y],newColor,delrow,delcol);
    return image;
}
