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
    bool k=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return k;
        }
        int s=0;
        bool f;
        f=dfs(root,sum,s);
        return f;
    }
    bool dfs(TreeNode* node, int sum, int s){
          s+=node->val;
        if(node->left==NULL && node->right==NULL){
            // cout<<s<<endl;
            if(sum==s)
                k= true;
            else 
                s=0;
        }
        
        if(node->left!=NULL)
            dfs(node->left,sum,s);
        if(node->right!=NULL)
             dfs(node->right,sum,s);
        if(k==true)
            return k ;
        return false;
        
    }
};