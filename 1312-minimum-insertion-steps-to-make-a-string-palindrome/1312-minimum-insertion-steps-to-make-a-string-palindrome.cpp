class Solution {
public:
    
//     int recur(int i, int j, string s, int n){
//         if(i >= j)
//             return 0;
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(s[i] == s[j])
//             return recur(i + 1, j - 1, s, n);
        
//         return dp[i][j] = min(1 + recur(i + 1, j, s, n), 1 + recur(i, j - 1, s, n));
//     }
    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                
                if(s[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return n - dp[n][n];
    }
};