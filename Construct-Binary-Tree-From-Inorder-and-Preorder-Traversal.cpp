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

TreeNode<int>* buildTree(int &preorderidx,int inorderstart,int inorderend,int n,vector<int>&inorder,vector<int>&preorder){
    if(preorderidx>=n || inorderstart>inorderend)   return NULL;
    int num = preorder[preorderidx++];
    TreeNode<int>* root = new TreeNode<int>(num);
    int idx = find(inorder.begin(),inorder.end(),num)-inorder.begin();
    root->left = buildTree(preorderidx,inorderstart,idx-1,n,inorder,preorder);
    root->right = buildTree(preorderidx,idx+1,inorderend,n,inorder,preorder);
    return root;

}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
    int preorderidx=0;
	  return buildTree(preorderidx,0,inorder.size()-1,inorder.size(),inorder,preorder);
}
