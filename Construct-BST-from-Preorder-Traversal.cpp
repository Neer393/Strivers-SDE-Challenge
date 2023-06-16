#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* buildBST(vector<int>&preorder,int *preorderidx,int key,int min,int max,int n){
    if(*preorderidx>=n){
        return NULL;
    }
    TreeNode<int>* root =NULL;
    if(key>min && key<max){
        root=new TreeNode<int>(key);
        *preorderidx= *preorderidx+1;

        if(*preorderidx<n){
            root->left=buildBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx < n){
            root->right=buildBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }

    }
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    int preorderidx=0;
    return buildBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,preorder.size());
}
