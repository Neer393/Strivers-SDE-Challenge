#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    map<char,int>mp1,mp2;
    for(int i=0;i<str1.length();i++)    mp1[str1[i]]++;
    for(int i=0;i<str2.length();i++)    mp2[str2[i]]++;
    return mp1==mp2;
}
