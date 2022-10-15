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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            
            mp[temp.second.second][temp.second.first].insert(temp.first->val);
                
            if(temp.first->left) q.push({temp.first->left, {temp.second.first + 1, temp.second.second - 1}});
            if(temp.first->right) q.push({temp.first->right, {temp.second.first + 1, temp.second.second + 1}});
            
        }
        
        vector<vector<int>> res;
        
        for(auto& i: mp){
            vector<int> temp;
            for(auto& j: i.second){
                for(auto& k: j.second)
                    temp.push_back(k);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};