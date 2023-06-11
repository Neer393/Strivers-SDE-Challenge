#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int>ans;
    vector<int> ptr(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],i});
    }
    while(!pq.empty()){
        pair<int,int> ele= pq.top();
        pq.pop();
        ans.push_back(ele.first);
        if(ptr[ele.second]+1 < kArrays[ele.second].size()){
            ptr[ele.second]++;
            pq.push({kArrays[ele.second][ptr[ele.second]],ele.second});
        }
    }
    return ans;
}
