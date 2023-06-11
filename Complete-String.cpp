#include <bits/stdc++.h> 

class TrieNode{
    public:
    TrieNode* children[26];
    bool isterminal =false;
    
    bool containskey(char ch){
        return children[ch-'a']!=NULL;
    }
    TrieNode* get(char ch){
        return children[ch-'a'];
    }
    void put(char ch,TrieNode* node){
        children[ch-'a']=node;
    }
    void setEnd(){
        isterminal=true;
    }
    bool isend(){
        return isterminal;
    }
};

class Trie{
  public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insertword(int n,vector<string>&a){
        for(int i=0;i<n;i++){
            TrieNode* node = root;
            for(int j=0;j<a[i].length();j++){
                if(!node->containskey(a[i][j])){
                    node->put(a[i][j],new TrieNode());
                }
                node=node->get(a[i][j]);
            }
            node->setEnd();
        }
    }
    
    bool checkPrefix(string word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
                if(!node->isend()){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
      Trie t;
      t.insertword(n,a);
      string longest="";
    for(int i=0;i<a.size();i++){
        if(t.checkPrefix(a[i])){
            if(a[i].length()>longest.length()){
                longest=a[i];
            }
            else if(longest.length()==a[i].length() && a[i]<longest){
                longest=a[i];
            }
        }
    }
    if(longest==""){
        return "None";
    }
    return longest;
}
