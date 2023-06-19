#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,false),curr(k+1,false);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notake=prev[j];
            bool take=false;
            if(arr[i]<=j)
                take = prev[j-arr[i]];
            curr[j]=take || notake;
        }
        prev=curr;
    }
    return prev[k];
}
