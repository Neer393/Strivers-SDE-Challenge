#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mp;
    for(auto i:arr) mp[i]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
    for(auto i:mp){
        pq.push({i.second,i.first});
    }
    vector<int>ans;
    while(!pq.empty() && k!=0){
        auto x = pq.top();
        pq.pop();
        ans.push_back(x.second);
        k--;
    }
    sort(ans.begin(),ans.end());
    return ans;
}
