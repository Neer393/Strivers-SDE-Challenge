#include <bits/stdc++.h> 

bool solve(int idx,int n,string temp,string &s,vector<string>&dictionary,vector<int>&dp){
    if(idx>=n)  return true;
    if(dp[idx]!=-1) return dp[idx];
    for(int i=idx;i<n;i++){
        temp.push_back(s[i]);
        if(find(dictionary.begin(),dictionary.end(),temp)!=dictionary.end()){
            if(solve(i+1,n,"",s,dictionary,dp))   return dp[idx]=true;
        }
    }
    return dp[idx]=false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int>dp(target.length(),-1);
    return solve(0,target.length(),"",target,arr,dp);
}
