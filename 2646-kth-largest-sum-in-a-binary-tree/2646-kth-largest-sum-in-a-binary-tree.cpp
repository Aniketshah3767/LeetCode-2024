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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ksum = 0;

        priority_queue<long long>pq;

        if(!root)
            return ksum;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            size_t size = q.size();
            long long sum = 0;
            for(int i = 0 ; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) 
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            pq.push(sum);
        }
    if(pq.size() < k)
        return -1;
    while(--k > 0)
        pq.pop();

    return pq.top();
    }
};