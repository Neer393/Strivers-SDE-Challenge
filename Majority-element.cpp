#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)	mp[arr[i]]++;
	for(auto i:mp){
		if(i.second > floor(n/2.0))	return i.first;
	}
	return -1;
}
