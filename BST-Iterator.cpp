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

class BSTiterator
{
    public:
    vector<TreeNode<int>*>arr;
    int i;
    BSTiterator(TreeNode<int> *root){
        inorder(root,arr);
        i=0;
    }

    void inorder(TreeNode<int> *root,vector<TreeNode<int> *>&arr){
        if(!root)   return;
        inorder(root->left,arr);
        arr.push_back(root);
        i++;
        inorder(root->right,arr);
    }

    int next(){
        if(i<arr.size())    return arr[i++]->data;
    }

    bool hasNext(){
        return i<arr.size();   
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
