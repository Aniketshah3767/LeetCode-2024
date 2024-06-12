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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)
        {
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        bool flag = 0;

        while(!q.empty()){
            vector<int> v1;
            int count = q.size();
            while(count--){
                TreeNode* curr = q.front();
                q.pop();
                v1.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(!flag)
            {
                ans.push_back(v1);
                flag = 1;
            }
            else{
                reverse(v1.begin(),v1.end());
                ans.push_back(v1);
                flag = 0;
            }
        }
        return ans;
    }
};