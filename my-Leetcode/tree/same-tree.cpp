// problem link:- https://leetcode.com/problems/same-tree/submissions/
 
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr)
            return true;
        if(p==nullptr)
            return false;
        if(q==nullptr)
            return false;
        if(p->val !=q->val)
            return false;
        bool flag;
        
        flag=true and isSameTree(p->left, q->left);
        
        return flag && isSameTree(p->right, q->right);
        
    }
};
