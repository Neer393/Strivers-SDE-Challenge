#include <bits/stdc++.h> 

int merge(vector<int>&arr,vector<int>&temp,int l,int mid,int r){
	int cnt=0;
	int temp2=mid+1;
	for(int temp=l;temp<=mid;temp++){
		while(temp2<=r && arr[temp]> 2LL*arr[temp2]){
			temp2++;
		}
		cnt+=(temp2-mid-1);
	}
	int i=l,j=mid+1,k=l;
	
	while(i<=mid && j<=r){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}
	for(i=l;i<=r;i++){
		arr[i]=temp[i];
	}
	return cnt;
}

int mergesort(vector<int>&arr,vector<int>&temp,int l,int r){
	int cnt=0;
	if(l<r){
		int mid = l+((r-l)/2);
		cnt+=mergesort(arr,temp,l,mid);
		cnt+=mergesort(arr,temp,mid+1,r);

		cnt+=merge(arr,temp,l,mid,r);
	}
	return cnt;
}

int reversePairs(vector<int> &arr, int n){
	vector<int>temp(n);
	return mergesort(arr,temp,0,n-1);	
}
