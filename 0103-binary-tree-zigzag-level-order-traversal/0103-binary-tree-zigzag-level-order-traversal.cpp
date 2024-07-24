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
        if(!root)
            return ans;

        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright = true;

        while(!q.empty()){
            int size = q.size();
            vector<int>row;
            for(int i =0 ; i < size;i++){
                auto tempnode = q.front();
                q.pop();


                row.push_back(tempnode->val);
            
                if(tempnode->left)
                    q.push(tempnode->left);
                if(tempnode->right)
                    q.push(tempnode->right);
            }
           
            if(!lefttoright){
                reverse(row.begin(),row.end());
            }
             lefttoright = !lefttoright;
            ans.push_back(row);
        }

    return ans;
    }
};