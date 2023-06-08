#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,int>mp;
    for(auto i:arr) mp[i]++;
    vector<int>newvec;
    for(auto i:mp)  newvec.push_back(i.first);
    sort(newvec.begin(),newvec.end());
    int maxi=1,cnt=1;
    for(int i=1;i<newvec.size();i++){
        if(newvec[i]-newvec[i-1]==1)    cnt++;
        else{
            maxi=max(maxi,cnt);
            cnt=1;
        }
    }
    maxi=max(maxi,cnt);
    return maxi;
}
