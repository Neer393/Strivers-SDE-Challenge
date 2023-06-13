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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>oq;
    int n=arr.size(),m=queries.size();
    vector<int>ans(m);
    for(int i=0;i<m;i++){
        oq.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oq.begin(),oq.end());
    int idx=0;
    Trie t;
    for(int i=0;i<m;i++){
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int oqidx=oq[i].second.second;
        while(idx<n && arr[idx]<=ai){
            t.insert(arr[idx]);
            idx++;
        }
        if(idx==0){
            ans[oqidx]=-1;
        }
        else{
            ans[oqidx]=t.getMax(xi);
        }
    }
    return ans;
}
