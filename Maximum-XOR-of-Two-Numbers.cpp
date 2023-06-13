#include <bits/stdc++.h> 

class TrieNode{
    public:
    TrieNode* children[2];
    TrieNode(){
        children[0]=NULL;
        children[1]=NULL;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* temp = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!temp->children[bit]){
                temp->children[bit]=new TrieNode();
            }
            temp = temp->children[bit];
        }
    }
    int getMax(int num){
        TrieNode* temp = root;
        int maxi =0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(temp->children[1-bit]){
                maxi = maxi | (1<<i);
                temp=temp->children[1-bit];
            }
            else{
                temp=temp->children[bit];
            }
        }
        return maxi;
    }
};

int maximumXor(vector<int> A)
{
    Trie t;
    for(auto i:A)   t.insert(i);
    int maxi=0;
    for(auto i:A){
        int ans = t.getMax(i);
        maxi=max(maxi,ans);
    }
    return maxi;
}
