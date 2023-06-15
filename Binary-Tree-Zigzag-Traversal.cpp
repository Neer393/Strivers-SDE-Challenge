#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(!root)   return ans;
    bool ltor = true;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        stack<int>st;
        for(int i=0;i<sz;i++){
            auto node= q.front();
            q.pop();
            if(ltor)    ans.push_back(node->data);
            else    st.push(node->data);
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);    
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        ltor = !ltor;
    }
    return ans;
}
