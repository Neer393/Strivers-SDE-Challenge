#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int>v;
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    return v[(n*m)/2];
}
