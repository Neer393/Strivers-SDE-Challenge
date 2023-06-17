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

int floorInBST(TreeNode<int> * root, int X)
{
    int ans;
    TreeNode<int> * temp = root;
    while(temp){
        if(X>temp->val){
            ans=temp->val;
            temp=temp->right;
        }
        else if(X<temp->val){
            temp=temp->left;
        }
        else{
            return X;
        }
    }
    return ans;
}
