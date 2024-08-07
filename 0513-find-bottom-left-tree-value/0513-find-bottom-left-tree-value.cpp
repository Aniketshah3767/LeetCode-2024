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
    int findBottomLeftValue(TreeNode* root) {
        //pair stores the node value and the height of the tree
        TreeNode* last = NULL;
        queue<TreeNode*>q;
        if(root)
            q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0  ; i < size ; i++){
                auto node = q.front();
                q.pop();
                if(i==0)
                    last = node;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
    return last->val;
        
    }
};