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

pair<int,int> diameter(TreeNode<int> *root){
    if(!root)   return {0,0};
    pair<int,int> lans = diameter(root->left);
    pair<int,int> rans = diameter(root->right);
    int ldiam = lans.first,lheight=lans.second;
    int rdiam = rans.first,rheight=rans.second;

    pair<int,int>ans;
    ans.first = max(lheight+rheight+1,max(ldiam,rdiam));
    ans.second = max(lheight,rheight)+1;
    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	return diameter(root).first-1;
}
