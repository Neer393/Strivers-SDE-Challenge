/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(){
        isTerminal = false;
        for(int i=0;i<26;i++)   children[i]=NULL;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->children[word[i]-'a']){
                temp->children[word[i]-'a']= new TrieNode();
            }
            temp=temp->children[word[i]-'a'];
        }
        temp->isTerminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->children[word[i]-'a'])    return false;
            temp=temp->children[word[i]-'a'];
        }
        return temp->isTerminal;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0;i<prefix.length();i++){
            if(!temp->children[prefix[i]-'a'])    return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};
