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
    #define ll long long
    int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, int>> q;
    int ans = 0;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        int nmin = q.front().second; // normalize index to prevent overflow

        int first = 0, last = 0; // Initialize first and last

        for (int i = 0; i < size; ++i) {
            int curr_id = q.front().second - nmin; // normalize the current index
            auto node = q.front().first;
            q.pop();
            
            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;

            if (node->left)
                q.push({node->left,(ll) curr_id * 2 + 1});
            if (node->right)
                q.push({node->right, (ll) curr_id * 2 + 2});
        }
        
        ans = max(ans, last - first + 1);
    }
    return ans;
}
};