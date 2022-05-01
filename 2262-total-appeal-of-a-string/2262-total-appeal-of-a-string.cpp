class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> ch(26,-1);
        long long curr = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            curr += i + 1 - (ch[s[i] - 'a'] == -1 ? 0 : ch[s[i] - 'a']);
            ch[s[i] - 'a'] = i + 1;
            ans += curr;
        }
        
        return ans;
    }
};