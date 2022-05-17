/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        if(!o || !c)
            return c;
        
        if(o==t)
            return c;
     
         const auto left = getTargetCopy(o->left,c->left,t);
        const auto right = getTargetCopy(o->right,c->right,t);
        return left?left:right;
    }
   
        
};