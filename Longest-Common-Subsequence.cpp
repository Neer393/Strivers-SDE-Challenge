#include<bits/stdc++.h>

int solve(int idx1,int idx2,string s,string t,vector<vector<int>>&dp){
    if(idx1<0 || idx2<0)    return 0;
    if(dp[idx1][idx2]!=-1)    return dp[idx1][idx2];
    if(s[idx1]==t[idx2])    return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,s,t,dp);
    return dp[idx1][idx2]=max(solve(idx1-1,idx2,s,t,dp),solve(idx1,idx2-1,s,t,dp));
}

int lcs(string s, string t){
    int n=s.length(),m=t.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])    curr[j]=1+prev[j-1];
                else    curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
	return prev[m];
}
