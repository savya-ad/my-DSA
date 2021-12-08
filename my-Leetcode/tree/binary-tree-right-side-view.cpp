// Problem link:- https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        if(root==NULL)
            return arr;
        queue<TreeNode*> q;
        q.push(root);
        int k=-1;
        while(!q.empty()){
            TreeNode* temp=q.front();
            arr.push_back(temp->val);
            
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
                q.pop();
            }
        }
        return arr;
    }
};
