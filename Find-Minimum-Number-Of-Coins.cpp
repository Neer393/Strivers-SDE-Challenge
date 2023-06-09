#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int ans=0;
    int arr[] = {1000,500,100,50,20,10,5,2,1};
    int idx=0;
    while(amount && idx<9){
        int curr = arr[idx];
        ans+=(amount/curr);
        amount = amount % curr;
        idx++;
    }
    return ans;
}
