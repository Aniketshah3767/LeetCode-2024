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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0; // Handle empty tree case

        std::queue<TreeNode*> q;
        std::vector<int> values;

        q.push(root);

        // BFS to collect values
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            values.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        sort(values.begin(), values.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            minDiff = min(minDiff, values[i] - values[i - 1]);
        }

        return minDiff;
    
    }
};