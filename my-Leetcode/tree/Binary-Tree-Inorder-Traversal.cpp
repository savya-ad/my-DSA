// Problem link-:  https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inorder(TreeNode*root, vector<int> &vect ){
        if(!root)
            return;
        if(root->left)
            inorder(root->left,vect);
        vect.push_back(root->val);
        if(root->right)
            inorder(root->right,vect);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return arr;
    }
};
