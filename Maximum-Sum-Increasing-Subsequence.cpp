#include <bits/stdc++.h> 

int solve(int idx,int n,vector<int>&rack,int prev,vector<vector<int>>&dp){
	if(idx>=n)	return 0;
	if(dp[idx][prev+1]!=-1)	return dp[idx][prev+1];
	int exclude = solve(idx+1,n,rack,prev,dp);
	int include=0;
	if(prev==-1 || rack[prev]<rack[idx]){
		include = rack[idx]+solve(idx+1,n,rack,idx,dp);
	}
	return dp[idx][prev+1]=max(include,exclude);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return solve(0,n,rack,-1,dp);
}
