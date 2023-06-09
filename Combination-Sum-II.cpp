#include<bits/stdc++.h>
void solve(int idx,int n,int target,set<vector<int>>&s,vector<int>&temp,vector<int>&arr){
	if(target==0){
		s.insert(temp);
		return;
	}
	if(idx>=n || target<0)	return;
	if(temp.empty()||(!temp.empty() && temp.back()!=arr[idx]))
		solve(idx+1,n,target,s,temp,arr);
	if(target>=arr[idx]){
		temp.push_back(arr[idx]);
		solve(idx+1,n,target-arr[idx],s,temp,arr);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(),arr.end());
	vector<int>temp;
	set<vector<int>> s;
	vector<vector<int>>ans;
	if(target==0)	return ans;
	solve(0,n,target,s,temp,arr);
	while(!s.empty()){
		auto x= *(s.begin());
		s.erase(x);
		ans.push_back(x);
	}	
	return ans;
}
