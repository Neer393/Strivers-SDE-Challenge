#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int n = s.length(),m=p.length();
    for(int i=0;i<=n-m;i++){
        string str = s.substr(i,m);
        if(str==p)  return true;
    }
    return false;
}
