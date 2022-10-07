class Solution {
public:

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i < m + 1; i++){
            if(p[i - 1] == '*')
                dp[0][i] = 1;
            else break;
        }
        
        for(int i = 1; i < n + 1; i++){
            
            for(int j = 1; j < m + 1; j++){
                
                if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                
                else if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                
            }
            
        }
        
        return dp[n][m];
    }
};