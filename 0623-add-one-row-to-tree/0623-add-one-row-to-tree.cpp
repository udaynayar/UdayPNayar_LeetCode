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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //freddie wants to break free
        //michael joins him with "hee hee"
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int x = 1;
        
        int d = depth-2;
        
        while (d--) {
            int y=0;
            
            while (x) {
                TreeNode* scam = q.front();
                q.pop();
                x--;

                if (scam->left) {
                    q.push(scam->left);
                    y++;
                }
                if (scam->right) {
                    q.push(scam->right);
                    y++;
                }
            }
            
            x += y;
            
            
        }
        
        while (!q.empty()) {
            
            TreeNode* sc = q.front();
            q.pop();
            
            TreeNode* n1 = new TreeNode(val, sc->left, nullptr);
            TreeNode* n2 = new TreeNode(val, nullptr, sc->right);
            sc->left = n1;
            sc->right = n2;
            
            
        }
        
        
        
        
        
        return root;
    }
};