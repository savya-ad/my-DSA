// Problem link:- https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
public:
    int minm(TreeNode* root){
        if(root==NULL)
            return INT_MAX;
        if(root->left==nullptr and root->right==nullptr)
            return 1;
        return 1+min(minm(root->left), minm(root->right));
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        return minm(root);
    }
};
 
