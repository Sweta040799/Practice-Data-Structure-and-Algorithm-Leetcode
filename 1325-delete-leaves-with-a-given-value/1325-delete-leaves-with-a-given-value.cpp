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
    bool isLeaf(TreeNode* node){
        if(node->right == NULL && node->left == NULL)
            return true;
        
        return false;
    }
    void DFS(TreeNode*& root, int target){
        if(!root) return;
        
        DFS(root->left, target);        
        DFS(root->right, target);
        
        if(root->val == target && isLeaf(root))
            root = NULL;
        
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        DFS(root, target);
        return root;
    }
};