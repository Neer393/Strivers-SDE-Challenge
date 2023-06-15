#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root){
    map<int,vector<int>>mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    mp[0].push_back(root->data);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        TreeNode<int> * temp = node.first;
        int hdis = node.second;
        if(temp->left){
            q.push({temp->left,hdis-1});
            mp[hdis-1].push_back(temp->left->data);
        }
        if(temp->right){
            q.push({temp->right,hdis+1});
            mp[hdis+1].push_back(temp->right->data);
        }
    }
    vector<int> ans;
    for(auto i:mp){
        for(auto j:i.second)    ans.push_back(j);
    }
    return ans;
}
