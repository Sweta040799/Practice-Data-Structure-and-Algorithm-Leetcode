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
    void DFS(TreeNode* root, int mx, int &cnt){
        if(!root) return;
        
        if(root->val >= mx){
            cnt++;
            mx = root->val;
        }
        
        DFS(root->left, mx, cnt);
        DFS(root->right, mx, cnt);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int mx = root->val, cnt = 0;
        
        DFS(root, mx, cnt);
        return cnt;
    }
};