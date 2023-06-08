#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(m==1 || n==1)    return;
    for(int times=0;times<min(n/2,m/2);times++){
        int pivot = mat[times][m-times-1];
        for(int i=m-times-1;i>times;i--){
            mat[times][i]=mat[times][i-1];
        }
        int newpivot = mat[n-times-1][m-times-1];
        for(int i=n-times-1;i>times;i--){
            mat[i][m-times-1]=mat[i-1][m-times-1];
        }
        mat[times+1][m-times-1]=pivot;
        pivot = newpivot;
        newpivot = mat[n-times-1][times];
        for(int i=times;i<m-times-1;i++){
            mat[n-times-1][i]=mat[n-times-1][i+1];
        }
        mat[n-times-1][m-times-2] = pivot;
        pivot=newpivot;
        for(int i=times;i<n-times-1;i++){
            mat[i][times] = mat[i+1][times];
        }
        mat[n-times-2][times]=pivot;
    }
}
