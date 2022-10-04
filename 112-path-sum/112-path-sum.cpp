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
    bool preorder(TreeNode* root, int sum, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) {
            sum += root->val;
            if(sum == targetSum) return true;
            return false;
        }    
        bool l = preorder(root->left,sum + root->val, targetSum);
        bool r = preorder(root->right,sum + root->val, targetSum);
        return (l || r);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preorder(root,0,targetSum);
    }
};