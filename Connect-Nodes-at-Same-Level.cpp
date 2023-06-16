#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        auto prev = q.front();
        q.pop();
        if(prev->left)  q.push(prev->left);
        if(prev->right) q.push(prev->right);
        for(int i=0;i<sz-1;i++){
            auto node=q.front();
            q.pop();
            prev->next=node;
            prev=node;
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        prev->next=NULL;
    }
}
