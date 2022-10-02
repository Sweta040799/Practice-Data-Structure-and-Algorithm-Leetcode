class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][31];
    int recur(int n, int k, int target, int face) {
        if(target == 0 && face == n) return 1;
        if(target == 0 || face == n) return 0;
        if(dp[target][face] != -1) return dp[target][face];
        
        int sum = 0;
        for(int i = 1; i <= k && target - i >= 0; i++) {
            sum = (sum + recur(n,k,target-i,face + 1)) % MOD;
        } 
        return dp[target][face] = sum;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return recur(n,k,target,0);
    }
};