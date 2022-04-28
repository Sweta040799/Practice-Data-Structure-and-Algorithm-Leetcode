class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), ans = 1;
        vector<int> dp(n,1);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], 1 + dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};