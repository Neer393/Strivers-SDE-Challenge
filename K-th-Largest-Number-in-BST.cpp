#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

int solve(TreeNode<int>* root,int &i, int k){
    if(!root)   return -1;
    int rans = solve(root->right,i,k);
    if(rans!=-1)    return rans;
    i++;
    if(i==k)    return root->data;
    return solve(root->left,i,k);
}

int KthLargestNumber(TreeNode<int>* root, int k) {
    int i=0;
    return solve(root,i,k);
}
