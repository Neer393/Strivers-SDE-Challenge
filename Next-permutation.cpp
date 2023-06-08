#include <bits/stdc++.h> 

void reverser(vector<int>&copy,int i,int j){
    while(i<j)  swap(copy[i++],copy[j--]);
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    vector<int>copy=permutation;
    if(n==0 || n==1)    return copy;
    int i=n-2;
    while(i>=0 && copy[i]>=copy[i+1])   i--;
    if(i>=0){
        int j=n-1;
        while(j>=0 && copy[j]<=copy[i]) j--;
        swap(copy[i],copy[j]);
    }
    reverser(copy,i+1,n-1);
    return copy;
}

