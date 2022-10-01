class Solution {
public:
    int dp[201];
    int recur(string s, int idx){
        if(idx == s.size())
            return 1;
        
        if(s[idx] == '0') return 0;
        
        if(idx == s.size() - 1) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int way1 = recur(s, idx + 1);
        int way2 = 0;
        string b = s.substr(idx, 2);
        
        if(stoi(b) <= 26 && stoi(b) > 0)
            way2 = recur(s, idx + 2);
        
        return dp[idx] = way1 + way2;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return recur(s, 0);
    }
};