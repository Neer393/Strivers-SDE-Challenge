#include<bits/stdc++.h>
long solve(int idx,int *num,int target,vector<vector<long>>&dp){
    if(idx==0){
        if(target%num[0]==0)    return 1;
        return 0;
    }
    if(dp[idx][target]!=-1)    return dp[idx][target];
    long notake = solve(idx-1,num,target,dp);
    long take=0;
    if(target>=num[idx])
        take=solve(idx,num,target-num[idx],dp);
    return dp[idx][target]=take+notake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return solve(n-1,denominations,value,dp);
}
