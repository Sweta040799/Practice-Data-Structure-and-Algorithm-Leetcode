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
    int Recur(TreeNode* root, int& mx){
        if(!root) return 0;
        
        int left = Recur(root->left,mx);
        int right = Recur(root->right,mx);
        
        mx = max(mx,left+right);
        
        return 1 + max(left,right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int mx = 0;
        Recur(root,mx);
        
        return mx;
    }
};