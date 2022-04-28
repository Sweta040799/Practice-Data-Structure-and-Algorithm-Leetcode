​Algorithm - Dynamic Programming
Type - Longest Increasing Subsequence Type

Recursive Code:

class Solution {
public:
    vector<int> ans;
    void Recur(vector<int>& nums, int prev, int curr, vector<int>& res){
        if(curr == nums.size()){
            if(res.size() > ans.size())
                ans = res;
            return;
        }
        
        if(prev == -1 || nums[curr] % nums[prev] == 0){
            res.push_back(nums[curr]);
            Recur(nums, curr, curr + 1, res);
            res.pop_back();
        }
        
        Recur(nums, prev, curr + 1, res);
        
    } 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        Recur(nums, -1, 0, res);
        return ans;
    }
};

  
  
