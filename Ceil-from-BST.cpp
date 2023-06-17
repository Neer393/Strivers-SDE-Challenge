#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    BinaryTreeNode<int> * temp = node;
    while(temp){
        if(x==temp->data)   return x;
        else if(x>temp->data){
            temp=temp->right;
        }
        else{
            ans=temp->data;
            temp=temp->left;
        }
    }
    return ans;
}
