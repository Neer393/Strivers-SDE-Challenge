#include <bits/stdc++.h> 

void solve(int idx,string temp,string&sentence,vector<string>&ans,int &n,string &s,unordered_map<string,int> &dictionary){
    if(idx>=n){
        ans.push_back(sentence);
        return;
    }
    for(int i=idx;i<n;i++){
        temp.push_back(s[i]);
        if(dictionary.find(temp)!=dictionary.end()){
            string ogsentence = sentence;
            if(sentence!="")    sentence.push_back(' ');
            sentence+=temp;
            solve(i+1,"",sentence,ans,n,s,dictionary);
            sentence = ogsentence;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>ans;
    string temp="",sentence="";
    int n = s.length();
    unordered_map<string,int> mp;
    for(auto i:dictionary)  mp[i]++;
    solve(0,temp,sentence,ans,n,s,mp);
    return ans;
}
