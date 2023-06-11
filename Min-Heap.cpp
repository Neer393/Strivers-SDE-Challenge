#include <bits/stdc++.h> 

void heapify(int i,int n,vector<int>&arr){
    int smallest = i;
    int l = 2*i +1;
    int r = 2*i +2;
    if(l<n && arr[l]<arr[i])    smallest = l;
    if(r<n && arr[r]<arr[i] && arr[r]<arr[l])    smallest = r;

    if(smallest !=i){
        swap(arr[i],arr[smallest]);
        heapify(smallest,n,arr);
    }
}

void insert(vector<int>&arr,int x){
    arr.push_back(x);
    int n = arr.size()-1;
    int startidx = ((n-1)/2);
    while(arr[startidx]>arr[n]){
        heapify(startidx,arr.size(),arr);
        n=startidx;
        startidx= (startidx-1)/2;
    }
}

int removeMin(vector<int>&arr){
    int ans = arr[0];
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    heapify(0,arr.size(),arr);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>heap;
    vector<int>ans;
    for(auto i:q){
        if(i[0]==0) insert(heap,i[1]);
        else    ans.push_back(removeMin(heap));
    }
    return ans;
}
