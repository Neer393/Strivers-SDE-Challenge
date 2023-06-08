#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>>ans;
  vector<long long int> temp;
  temp.push_back(1);
  ans.push_back(temp);
  if(n==1)  return ans;
  temp.push_back(1);
  ans.push_back(temp);
  if(n==2)  return ans;
  temp.clear();
  for(int i=3;i<=n;i++){
    vector<long long int> newvec(i);
    newvec[0]=1;
    newvec[i-1]=1;
    for(int j=1;j<i-1;j++){
      newvec[j]=ans.back()[j-1]+ans.back()[j];
    }
    ans.push_back(newvec);
  }
  return ans;
}
