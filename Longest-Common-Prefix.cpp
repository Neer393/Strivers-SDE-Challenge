#include<bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    int idx=0;
    int len=INT_MAX;
    for(auto i:arr) len=min(len,(int)(i.length()));
    string ans="";
    while(idx<len){
        char currchar = arr[0][idx];
        for(int i=1;i<n;i++){
            if(arr[i][idx]!=currchar)   return ans;
        }
        ans.push_back(currchar);
        idx++;
    }
    return ans;
}
