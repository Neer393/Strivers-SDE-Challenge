#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int freq[n+1]={0};
	for(auto i:arr)	freq[i]++;
	int missing,repeat;
	for(int i=1;i<=n;i++){
		if(freq[i]==0)	missing=i;
		else if(freq[i]>1)	repeat=i;
	}
	return {missing,repeat};
}
