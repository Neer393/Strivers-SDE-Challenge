#include <bits/stdc++.h> 

bool ispalindrome(string str){
    string temp=str;
    reverse(temp.begin(),temp.end());
    return temp==str;
}

int solve(int idx,int &n,string &str,vector<int>&dp){
    if(idx>=n)    return 0;
    if(dp[idx]!=-1)    return dp[idx];
    int mincost=INT_MAX;
    string temp="";
    for(int i=idx;i<n;i++){
        temp+=str[i];
        if(ispalindrome(temp)){
            int cost=1+solve(i+1,n,str,dp);
            mincost=min(mincost,cost);
        }
    }
    return dp[idx]=mincost;
}

int palindromePartitioning(string str) {
     int n=str.length();
    vector<int>dp(n,-1);
    return solve(0,n,str,dp)-1;
}
