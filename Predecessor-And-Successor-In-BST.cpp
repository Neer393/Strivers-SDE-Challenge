#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1,succ=-1;
    BinaryTreeNode<int>* temp =root;
    while(temp->data!=key){
        if(key>temp->data){
            pre=temp->data;
            temp=temp->right;
        }
        else{
            succ=temp->data;
            temp=temp->left;
        }
    }
    
    BinaryTreeNode<int>* lefttree =temp->left;
    while(lefttree!=NULL){
        pre = lefttree->data;
        lefttree=lefttree->right;
    }
    
    BinaryTreeNode<int>* righttree =temp->right;
    while(righttree!=NULL){
        succ = righttree->data;
        righttree=righttree->left;
    }
    return {pre,succ};
}
