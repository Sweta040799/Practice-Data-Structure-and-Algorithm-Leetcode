class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        int max_ele = *max_element(nums.begin(), nums.end());
        
        int curr_sum = 0, max_sub = INT_MIN, min_sub = INT_MAX, ans;
        
        for(int i = 0; i < n; i++){
            curr_sum += nums[i];
            if(curr_sum < min_sub)
                min_sub = curr_sum;
            if(curr_sum >= 0)
                curr_sum = 0;
        }
        
        for(int i = 0; i < n; i++){
            curr_sum += nums[i];
            if(curr_sum > max_sub)
                max_sub = curr_sum;
            if(curr_sum < 0)
                curr_sum = 0;
        }
        
        ans = max(tot_sum - min_sub, max_sub);
        if(ans == 0) ans = max_ele;
        
        return ans;
    }
};