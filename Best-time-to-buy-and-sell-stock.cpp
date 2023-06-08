#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    vector<int>prevmin(n);
    prevmin[0]=INT_MAX;
    for(int i=1;i<n;i++){
        prevmin[i]=min(prevmin[i-1],prices[i-1]);
    }
    int maxprofit = 0;
    for(int i=1;i<n;i++){
        maxprofit = max(maxprofit,prices[i]-prevmin[i]);
    }
    return maxprofit;
}
