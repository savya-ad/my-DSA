// Problem link:- https://leetcode.com/problems/house-robber-iii/

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
    int findmax(TreeNode *root, unordered_map<TreeNode *, int> &dp){
        if(root == nullptr) 
            return 0;
        if(dp.find(root) != dp.end()) 
            return dp[root];
        if(root->left == nullptr && root->right == nullptr) 
            return root->val;
        
        int pick_current = root->val;
        int left = root->left ? findmax(root->left->left, dp) + findmax(root->left->right, dp) : 0;
        int right = root->right ? findmax(root->right->left, dp) + findmax(root->right->right, dp) : 0;
        int ignore_current = findmax(root->left, dp) + findmax(root->right, dp);
        
        pick_current += (left + right);
        
        return dp[root] = max(pick_current, ignore_current);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return findmax(root, dp);
    }
};
