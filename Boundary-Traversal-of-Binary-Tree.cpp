#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void printLeft(TreeNode<int>* root,vector<int>&ans){
    TreeNode<int>* temp = root->left;
    while(temp){
        if(temp->left || temp->right)    ans.push_back(temp->data);
        if(temp->left)  temp=temp->left;
        else    temp=temp->right;
    }
}

void printLeaf(TreeNode<int>* root,vector<int>&ans){
    if(!root)   return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    printLeaf(root->left,ans);
    printLeaf(root->right,ans);
}

void printRight(TreeNode<int>* root,vector<int>&ans){
    TreeNode<int>* temp = root->right;
    stack<int>st;
    while(temp){
        if(temp->left || temp->right)   st.push(temp->data);
        if(temp->right) temp=temp->right;
        else    temp=temp->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root)   return ans;
    if(root->left || root->right) ans.push_back(root->data);
    printLeft(root,ans);
    printLeaf(root,ans);
    printRight(root,ans);
    return ans;
}
