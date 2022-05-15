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
      
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        
        
        queue<TreeNode*> q;
         int s=0;
        q.push(root);
        
        while(!q.empty()){
            s=0;
            q.push(NULL);
            
            while(true){
                TreeNode* t = q.front();
                q.pop();
                
                if(t==NULL)
                    break;
                
                s+=t->val;
                if(t->left!= NULL)
                    q.push(t->left);
                
                if(t->right!= NULL)
                    q.push(t->right);
            }
            
            
        }
       
        return s;
    }
    
    
};