#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void flatten(TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        struct TreeNode<int>*temp = root->right;
        root->right=root->left;
        root->left=NULL;
        struct TreeNode<int>* t = root;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    flatten(root);
    return root;
}
