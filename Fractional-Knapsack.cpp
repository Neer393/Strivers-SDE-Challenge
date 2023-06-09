#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),[&](pair<int,int>&a,pair<int,int>&b){
        return a.second/(a.first*1.0) > b.second/(b.first*1.0);
    });
    double sum=0;
    int currwt=0;
    for(auto i:items){
        if(currwt+i.first <= w){
            sum+=i.second;
            currwt+=i.first;
            if(currwt==w)   return sum;
        }
        else{
            sum+=(w-currwt)*(i.second/(i.first*1.0));
            currwt=w;
            return sum;
        }
    }
    return sum;
}
