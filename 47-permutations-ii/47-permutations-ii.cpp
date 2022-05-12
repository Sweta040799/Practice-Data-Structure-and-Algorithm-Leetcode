class Solution {
public:
    void Combination(vector<int>& nums, set<vector<int>>& temp, int curr){
        if(curr == nums.size()){
            temp.insert(nums);
            return;
        }
        
        for(int i = curr; i < nums.size(); i++){
            swap(nums[i],nums[curr]);
            Combination(nums, temp, curr + 1);
            swap(nums[i],nums[curr]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> temp;
        vector<vector<int>> ans;
        
        Combination(nums, temp, 0);
        
        for(auto& i : temp)
            ans.push_back(i);
        
        return ans;
    }
};