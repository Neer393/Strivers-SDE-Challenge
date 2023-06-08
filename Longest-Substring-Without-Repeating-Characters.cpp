#include <bits/stdc++.h> 

int uniqueSubstrings(string input)
{
    unordered_map<char,int> mp;
    int maxi=0,len=input.length(),previdx=0;
    for(int i=0;i<len;i++){
        if(mp.empty()){
            mp[input[i]]=i;
            maxi=max(maxi,1);
            continue;
        }
        if(mp.find(input[i])==mp.end()){
            mp[input[i]]=i;
            int sz = mp.size();
            maxi=max(maxi,sz);
        }
        else{
            while(previdx<i && input[previdx]!=input[i]){
                mp.erase(input[previdx]);
                previdx++;
            }
            if(previdx<i)   previdx++;
        }

    }
    return maxi;
}
