class Solution {
public:
  
    int countSubstrings(string s) {
        int n = s.size() ;
        vector<vector<int>> dp(n,vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i < n ; i++)
            dp[i][i] = 1, ++ans;
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = n-1 ; j > i ; j--){
                if(s[i] == s[j]){
                    if(i+1 == j || dp[i+1][j-1])
                       dp[i][j] = 1, ++ans;
                } 
            }
        }
       return ans;
    }
};