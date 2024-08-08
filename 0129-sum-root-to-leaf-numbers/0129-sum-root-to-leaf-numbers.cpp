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
    void findsum(TreeNode* root , int curr , int &ans){
        if(!root)
            return;
        
        if (root->left == nullptr && root->right == nullptr)
            ans += (curr * 10 + root->val);
        curr = curr * 10 + root->val;
        findsum(root->left,curr,ans);
        findsum(root->right,curr,ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        findsum(root,0,ans);
        return ans;

    }
};