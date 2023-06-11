#include <bits/stdc++.h> 

bool check(vector<int> time,long long mid,int n,int m){
	long long daysreq=1,hrs=0;
	for(int i=0;i<m;i++){
		if(time[i]>mid)	return false;
		if(hrs+time[i]<=mid){
			hrs+=time[i];
		}
		else{
			hrs=time[i];
			daysreq++;
			if(daysreq>n)	return false;
		}
	}
	return daysreq<=n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	

	long long s=1,e=0;
	for(auto i:time)	e+=i;
	long long ans=e;
	while(s<=e){
		long long mid = s+((e-s)/2);
		if(check(time,mid,n,m)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}
