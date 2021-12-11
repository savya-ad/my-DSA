// Problem link:- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int, int> mp;
    int preindex=0;
public:
    TreeNode* constructBtree(vector<int>& preorder, int left, int right){
        if(left>right)  return nullptr;
        int rootElem=preorder[preindex++];
        
        TreeNode* root=new TreeNode(rootElem);
        int found=mp[rootElem];
               
        root->left=constructBtree(preorder, left, found-1);
        
        root->right=constructBtree(preorder, found+1, right);
        return root;
            
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return constructBtree(preorder,0,n-1);
    }
};
