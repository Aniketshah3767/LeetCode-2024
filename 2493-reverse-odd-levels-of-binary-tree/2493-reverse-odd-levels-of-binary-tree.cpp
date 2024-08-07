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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)
            return root;
        
        vector<int>ans;

        // bool flag = 1;
        // while(!q.empty()){
        //     int n = q.size();
        //     for(int i = 0 ; i < n ; i++){
        //         auto node = q.front();
        //         q.pop();
        //         if(i==0)
        //             ans.push_back(node);
        //         if(node->left)
        //             q.push(node->left);
                
        //         if(node->right)
        //             q.push(node->right);
        //     }
        //     n = temp.size();
        //     for(int i = 0 ; i < n/2 ; i++){
        //         int z = ans[i]->val;
        //         ans[i]->val = ans[n-1-i]->val;
        //         ans[n-1-i]-val = z;
        //     }
        // }
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i = 0 ; i < size ; i++){
                auto node = q.front();
                q.pop();
                if(level%2){
                    node->val = ans[size-i-1];
                }
                if(node ->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            ans = temp;
            level++;
        }
        return root;
        
    }
};