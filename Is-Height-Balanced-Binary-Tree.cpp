#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

pair<int,bool> solve(BinaryTreeNode<int>* root){
    if(!root)   return {0,true};
    pair<int,bool> lans = solve(root->left);
    pair<int,bool> rans = solve(root->right);

    pair<int,bool>ans;
    ans.first = max(lans.first,rans.first)+1;
    ans.second = lans.second && rans.second && abs(lans.first-rans.first)<=1;
    return ans;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return solve(root).second;
}
