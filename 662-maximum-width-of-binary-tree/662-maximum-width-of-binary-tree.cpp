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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int curr_level = INT_MIN;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            int start_idx = q.front().first;
            int sz = q.size(), first, last;
            for(int i = 0; i < sz; i++){
                long long int curr_idx = q.front().first - start_idx;
                if(i == 0)
                    first = q.front().first;
                if(i == sz - 1)
                    last = q.front().first;
                
                TreeNode* node = q.front().second;
                q.pop();
                    
                if(node->left) q.push({2 * curr_idx + 1, node->left});
                if(node->right) q.push({2 * curr_idx + 2, node->right});
            }
            curr_level = max(curr_level, last - first + 1);
        }
        return curr_level;
    }
};