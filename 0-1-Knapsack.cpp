#include <bits/stdc++.h>

int solve3(vector<int> &weight, vector<int> &value, int n,int capacity){
    vector<int>prev(capacity+1,0);
    for(int i=weight[0];i<=capacity;i++)
        prev[i]=value[0];
    for(int i=1;i<n;i++){
        for(int j=capacity;j>=0;j--){
            int include =0;
            if(weight[i]<=j)
               include = value[i]+prev[j-weight[i]];
            int exclude = prev[j];
            prev[j]=max(include,exclude);
        }
    }
    return prev[capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	return solve3(weights,values,n,w);
}
