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
  
    int Recur(TreeNode* node, int &cnt){
        int left = node->left ? Recur(node->left, cnt) : 0;
        int right = node->right ? Recur(node->right, cnt) : 0;
        
        int left_val = node->left && node->left->val == node->val ? left + 1 : 0;
        int right_val = node->right && node->right->val == node->val ? right + 1 : 0;
        
        cnt = max(cnt, left_val + right_val);
        
        return max(left_val, right_val);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        
        Recur(root, cnt);
        
        return cnt;
    }
};