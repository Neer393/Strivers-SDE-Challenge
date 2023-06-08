#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    int maxi=INT_MIN;
    long long int maxans = 0;
    long long int sum=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        sum+=arr[i];
        if(sum<0)   sum=0;
        maxans = max(maxans,sum);
    }
    if(maxi<=0)  return 0;
    return maxans;
}
