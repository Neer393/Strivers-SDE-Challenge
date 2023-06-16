#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* build(int l,int r,vector<int> &arr){
    if(l>r) return NULL;
    int mid = l+((r-l)/2);
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = build(l,mid-1,arr);
    root->right = build(mid+1,r,arr);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return build(0,n-1,arr);
}
