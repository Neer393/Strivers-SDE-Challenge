#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(TreeNode<int>* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    Info leftinfo =largestBSTinBT(root->left);
    Info rightinfo=largestBSTinBT(root->right);

    Info curr;
    curr.size= (1+leftinfo.size+rightinfo.size);
    if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->data && rightinfo.min>root->data){
        curr.min = min(root->data,min(leftinfo.min,rightinfo.min));
        curr.max = max(root->data,max(leftinfo.max,rightinfo.max));
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.isBST=false;
    return curr;
}

int largestBST(TreeNode<int>* root) 
{
    return largestBSTinBT(root).ans;
}
