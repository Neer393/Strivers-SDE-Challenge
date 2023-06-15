#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,int>mp;
    vector<int>ans;
    if(!root)   return ans;
    queue<pair<BinaryTreeNode<int> *,int>>q;
    q.push({root,0});
    mp[0]=root->data;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        BinaryTreeNode<int> * temp = node.first;
        int hdis = node.second;
        if(temp->left){
            q.push({temp->left,hdis-1});
            mp[hdis-1]=temp->left->data;
        }
        if(temp->right){
            q.push({temp->right,hdis+1});
            mp[hdis+1]=temp->right->data;
        }
    }
    for(auto i:mp)  ans.push_back(i.second);
    return ans;
}
