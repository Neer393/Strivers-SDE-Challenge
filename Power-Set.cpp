#include <bits/stdc++.h> 

void solve(int idx,int &n,vector<int>&v,vector<int>&temp,vector<vector<int>>&ans){
    if(idx>=n){
        ans.push_back(temp);
        return;
    }
    solve(idx+1,n,v,temp,ans);
    temp.push_back(v[idx]);
    solve(idx+1,n,v,temp,ans);
    temp.pop_back();
}

vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    vector<int>temp;
    vector<vector<int>> ans;
    solve(0,n,v,temp,ans);
    return ans;
}
