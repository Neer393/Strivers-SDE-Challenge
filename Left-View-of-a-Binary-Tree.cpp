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

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    if(!root)   return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        ans.push_back(q.front()->data);
        for(int i=0;i<sz;i++){
            auto node = q.front();
            q.pop();
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans;
}
