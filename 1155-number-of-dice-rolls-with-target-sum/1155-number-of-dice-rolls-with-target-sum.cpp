class Solution {
public:
    const int mx = 1e9 + 7;
    int dp[1001][31];
    int Recur(int face, int target, int k ,int n){
        if(target == 0 && face == n) return 1;
        if(target == 0 || face == n) return 0;
        
        if(dp[target][face] != -1) return dp[target][face];
        
        int sum = 0;
        for(int i = 1; i <= k && target - i >= 0; i++){
            sum = (sum + Recur(face + 1, target - i, k, n)) % mx;
        }
        
        return dp[target][face] = sum % mx;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return Recur(0, target, k, n);
    }
};