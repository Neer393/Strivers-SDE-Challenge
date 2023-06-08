#include <bits/stdc++.h> 

long long merge(long long *arr,long long *temp,int l,int mid,int r){
    int i=l,j=mid,k=l;
    long long cnt=0;
    while(i<=mid-1 && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            cnt +=(mid-i);
        }
    }
    while(i<=mid-1){
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

long long mergesort(long long *arr,long long *temp,int l,int r){
    long long cnt = 0;
    if(l<r){
        int mid = l+((r-l)/2);
        cnt+=mergesort(arr,temp,l,mid);
        cnt+=mergesort(arr,temp,mid+1,r);

        cnt+=merge(arr,temp,l,mid+1,r);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    long long temp[n];
    return mergesort(arr,temp,0,n-1);
}
