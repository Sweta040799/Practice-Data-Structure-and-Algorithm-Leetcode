/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* Recur(vector<int>& nums, int low, int high){
        if(low > high) return NULL;
        
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = Recur(nums, low, mid - 1);
        root->right = Recur(nums, mid + 1, high);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        
        return Recur(nums, 0, nums.size() - 1);
    }
};