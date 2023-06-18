#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
int solve(TreeNode<int>* root,int &i, int k){
    if(!root)   return -1;
    int lans = solve(root->left,i,k);
    if(lans!=-1)    return lans;
    i++;
    if(i==k)    return root->data;
    return solve(root->right,i,k);
}

int kthSmallest(TreeNode<int> *root, int k){
	int i=0;
    return solve(root,i,k);
}
