#include <bits/stdc++.h> 

void solve(int idx,int n,vector<int>&arr,vector<int>&temp,set<vector<int>>&s){
    if(idx>=n){
        vector<int>tempo = temp;
        sort(tempo.begin(),tempo.end());
        s.insert(tempo);
        return;
    }
    solve(idx+1,n,arr,temp,s);

    temp.push_back(arr[idx]);
    solve(idx+1,n,arr,temp,s);
    temp.pop_back();
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>>s;
    vector<int>temp;
    solve(0,n,arr,temp,s);
    vector<vector<int>> ans;
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        ans.push_back(x);
    }
    return ans;
}
