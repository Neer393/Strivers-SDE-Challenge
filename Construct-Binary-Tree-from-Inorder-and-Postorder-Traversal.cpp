/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

TreeNode<int>* buildTree(int &postorderidx,int inorderstart,int inorderend,int n,vector<int>&inorder,vector<int>&postorder){
    if(postorderidx<0 || inorderstart>inorderend)   return NULL;
    int num = postorder[postorderidx--];
    TreeNode<int>* root = new TreeNode<int>(num);
    int idx = find(inorder.begin(),inorder.end(),num)-inorder.begin();
    root->right = buildTree(postorderidx,idx+1,inorderend,n,inorder,postorder);
    root->left = buildTree(postorderidx,inorderstart,idx-1,n,inorder,postorder);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	int postorderidx=inorder.size()-1;
	return buildTree(postorderidx,0,inorder.size()-1,inorder.size(),inorder,postorder);
}
