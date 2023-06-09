#include <bits/stdc++.h> 

bool isPalindrome(string &s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j])  return false;
        i++;
        j--;
    }
    return true;
}

void solve(int idx,int &n,string &s,string &tempo,vector<string>&temp,vector<vector<string>>&ans){
    if(idx>=n){
        if(isPalindrome(tempo))
            ans.push_back(temp);
        return;
    }
    for(int i=idx;i<n;i++){
        tempo.push_back(s[i]);
        if(isPalindrome(tempo)){
            string newtempo="";
            temp.push_back(tempo);
            solve(i+1,n,s,newtempo,temp,ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s){
    vector<vector<string>>ans;
    vector<string>temp;
    string tempo;
    int n=s.length();
    solve(0,n,s,tempo,temp,ans);
    return ans;
}
