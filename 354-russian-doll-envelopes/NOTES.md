Algorithm: Dynamic Programming
Type: Longest Increasing Subsequence Type

Recursive Code:

class Solution {
public:
    int Recur(vector<vector<int>>& envelopes, int prev, int curr){
        if(curr == envelopes.size())
            return 0;
        
        int left = 0;
        if(prev == -1 || (envelopes[prev][0] < envelopes[curr][0] && envelopes[prev][1] < envelopes[curr][1])){
            left = 1 + Recur(envelopes, curr, curr + 1);
        }
        
        int right = Recur(envelopes, prev, curr + 1);
        
        return max(left, right);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        return Recur(envelopes, -1, 0);
    }
};
  
Memoized Code + Space Optimized:
  
class Solution {
public:
    int dp[100001];
    int Recur(vector<vector<int>>& envelopes, int prev, int curr){
        if(curr == envelopes.size())
            return 0;
        
        if(prev != -1 && dp[prev] != 0)
            return dp[prev];
        
        int left = 0;
        if(prev == -1 || (envelopes[prev][0] < envelopes[curr][0] && envelopes[prev][1] < envelopes[curr][1])){
            left = 1 + Recur(envelopes, curr, curr + 1);
        }
        
        int right = Recur(envelopes, prev, curr + 1);
        
        if(prev != -1)
          return dp[prev] = max(left, right);
        
        return max(left,right);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        memset(dp,0,sizeof(dp));
        return Recur(envelopes, -1, 0);
    }
};
  
#Tabulation Code:
  
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size(), ans = 1;
        vector<int> dp(n,1);
        
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans,dp[i]);
        } 
        
        return ans;
    }
};
