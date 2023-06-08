#include <bits/stdc++.h> 

bool threesum(vector<int> arr, int target, int idx,int n){
    for(int i=idx+1;i<n-2;i++){
        int newtar = target-arr[i];
        int s=i+1,e=n-1;
        while(s<e){
            int sum = arr[s]+arr[e];
            if(sum==newtar){
                return true;
            }
            else if(sum<newtar) s++;
            else    e--;
        }
    }
    return false;
}

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        if(threesum(arr,target-arr[i],i,n)) return "Yes";
    }
    return "No";
}
