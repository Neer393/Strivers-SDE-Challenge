#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int>ans(m+n);
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			ans[k++]=arr1[i++];
		}
		else{
			ans[k++]=arr2[j++];
		}
	}
	while(i<m){
		ans[k++]=arr1[i++];
	}
	while(j<n){
		ans[k++]=arr2[j++];
	}
	arr1=ans;
	return ans;
}
