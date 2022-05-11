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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode *curr = root, *prev;
        
        while(curr){
            prev = curr;
            if(val < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        
        if(val < prev->val){
           prev->left = new TreeNode(val); 
        }
        else{
            prev->right = new TreeNode(val);
        }
        
        return root;
    }
};