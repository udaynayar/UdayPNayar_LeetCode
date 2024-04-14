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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> treenode;
        queue<bool> check;
        
        treenode.push(root);
        check.push(false);
        
        int x = 0;
        
        while (!treenode.empty()) {
            
            if (check.front() && !treenode.front()->left && !treenode.front()->right) {
                x += treenode.front() -> val;
            }
            
            TreeNode* c = treenode.front();
            treenode.pop(); check.pop();
            
            if (c->left) {
                
                treenode.push(c->left);
                check.push(true);
            }
            if (c->right) {
                treenode.push(c->right);
                check.push(false);
            }
            
            
            
        }
        
        
        return x;
    }
};