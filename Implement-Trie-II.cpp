#include <bits/stdc++.h> 

class TrieNode{
  public:
    TrieNode* children[26];
    int cntEndWith=0;
    int cntPrefix=0;
    
    bool containskey(char ch){
        return children[ch-'a']!=NULL;}
    TrieNode* get(char ch){
        return children[ch-'a'];}
    void put(char ch,TrieNode* node){
        children[ch-'a']=node;
    }
        
    void increaseEnd(){
        cntEndWith++;}
    void increasePrefix(){
        cntPrefix++;}
    void decreaseEnd(){
        cntEndWith--;}
    void decreasePrefix(){
        cntPrefix--;}
    int getEnd(){
        return cntEndWith;}
    int getPrefix(){
        return cntPrefix;}
};

class Trie{

    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string &word){
        TrieNode* node =root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        TrieNode* node =root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]);
                node->decreasePrefix();
            }
            else{
                return;
            }
        }
        node->decreaseEnd();
    }
};
