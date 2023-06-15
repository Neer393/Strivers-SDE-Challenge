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

int LCA(TreeNode<int> *root, int x, int y){
    if(!root)   return -1;
    if(root->data == x || root->data == y)  return root->data;
    int leftLCA = LCA(root->left,x,y);
    int rightLCA = LCA(root->right,x,y);
    if(leftLCA!=-1 && rightLCA!=-1) return root->data;
    else if(leftLCA==-1 && rightLCA!=-1)    return rightLCA;
    return leftLCA;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return LCA(root,x,y);
}
