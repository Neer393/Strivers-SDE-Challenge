#include <bits/stdc++.h> 

class TrieNode{
    public:
    TrieNode* children[26];
    TrieNode() {
      for (int i = 0; i < 26; i++)
        children[i] = NULL;
    }
};

int distinctSubstring(string &word) {
    int cnt=0,n=word.length();
    TrieNode* root = new TrieNode();
    for(int i=0;i<n;i++){
        TrieNode* temp=root;
        for(int j=i;j<n;j++){
            if(!temp->children[word[j]-'a']){
                cnt++;
                temp->children[word[j]-'a']=new TrieNode();
            }
            temp=temp->children[word[j]-'a'];
        }
    }
    return cnt;
}
