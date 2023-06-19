int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    vector<int>prev(n+1,0);
    for(int i=0;i<=n;i++)    prev[i]=price[0]*i;
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notake = prev[j];
    int take=0;
    if(i+1<=j)
        take = price[i]+prev[j-i-1];
         prev[j]=max(take,notake);
        }
    }
	return prev[n];
}
