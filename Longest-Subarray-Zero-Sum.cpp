#include <bits/stdc++.h> 

int LongestSubsetWithZeroSum(vector < int > arr) {
  unordered_map<int,int>mp;
  int sum=0,maxi=0,n=arr.size();
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0)  maxi=i+1;
    else{
      if(mp.find(sum)!=mp.end())  maxi=max(maxi,i-mp[sum]);
      else mp[sum]=i;
    }
  }
  return maxi;
}
