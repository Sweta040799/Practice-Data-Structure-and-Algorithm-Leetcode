class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mx = -1, idx;
        vector<int> dp(n,1), hash(n,-1), ans;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1){
                    dp[j] = dp[i] + 1;
                    hash[j] = i;
                }
            }
            if(mx < dp[i]){
                mx = dp[i];
                idx = i;
            }
        }
        
        while(idx > -1){
            ans.push_back(nums[idx]);
            idx = hash[idx];
        }
        
        return ans;
    }
};