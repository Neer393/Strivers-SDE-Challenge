#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    map<int,int>mp;
    vector<int>ans;
    if(!root)   return ans;
    queue<pair<TreeNode<int> *,int>>q;
    q.push({root,0});
    mp[0]=root->val;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        TreeNode<int> * temp = node.first;
        int hdis = node.second;
        if(temp->left){
            q.push({temp->left,hdis-1});
            if(mp.find(hdis-1)==mp.end())   mp[hdis-1]=temp->left->val;
        }
        if(temp->right){
            q.push({temp->right,hdis+1});
            if(mp.find(hdis+1)==mp.end())   mp[hdis+1]=temp->right->val;
        }
    }
    for(auto i:mp)  ans.push_back(i.second);
    return ans;
}
