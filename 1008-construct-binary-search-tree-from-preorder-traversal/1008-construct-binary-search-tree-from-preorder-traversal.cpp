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
    TreeNode* Recur(TreeNode* root, int s){
        TreeNode *curr = root, *prev;
        
        while(curr != NULL){
            prev = curr;
            if(s < curr->val){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        
        if(s < prev->val){
            prev->left = new TreeNode(s);
        }
        else{
            prev->right = new TreeNode(s);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < n; i++){
            root = Recur(root, preorder[i]);
        }
        
        return root;
    }
};