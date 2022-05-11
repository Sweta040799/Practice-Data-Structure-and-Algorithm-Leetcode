class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][6];
        
        for(int i=1;i<6;i++)
            dp[0][i]=1;
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<6;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[n][5];
        
    }
};