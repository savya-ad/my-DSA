// Problem link:- https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int ans;
public:
    void solve(TreeNode* root, int sum){
        if(root==NULL)
            return ;
        sum=sum*10 +root->val;
        if(!root->left and !root->right){
            ans+=sum;
            return;
        }
        solve(root->left, sum);
        solve(root->right, sum);
        
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        solve(root, 0);
        return ans;
    }
};
