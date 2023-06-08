#include <bits/stdc++.h> 

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int>mp;
    int cnt=0,ansxor=0,n=arr.size();
    for(int i=0;i<n;i++){
        ansxor = ansxor xor arr[i];
        if(ansxor==x)   cnt++;
        if(mp.find(ansxor xor x)!=mp.end()) cnt+=mp[ansxor xor x];
        mp[ansxor]++;
    }
    return cnt;
}
