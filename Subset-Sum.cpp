#include <bits/stdc++.h> 

void solve(int idx,int n,int &sum,vector<int>&ans,vector<int>&num){
    if(idx>=n){
        ans.push_back(sum);
        return;
    }
    solve(idx+1,n,sum,ans,num);
    sum+=num[idx];
    solve(idx+1,n,sum,ans,num);
    sum-=num[idx];
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans;
    int sum=0;
    solve(0,num.size(),sum,ans,num);
    sort(ans.begin(),ans.end());
    return ans;
}
