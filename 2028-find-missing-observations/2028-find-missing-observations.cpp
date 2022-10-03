class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum_m = accumulate(rolls.begin(),rolls.end(),0);
        int sum_n = (mean * (m+n)) - sum_m;
        int ele = sum_n/n;
        int rem = sum_n%n;
        if(sum_n < n || ele > 6 || (ele >= 6 && rem > 0))
            return {};
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++) {
            ans[i] = ele;
            if(rem > 0) {
                if(rem >= 6 - ans[i]) {
                    rem -= (6 - ans[i]);
                    ans[i] = 6;
                }
                else {
                    ans[i] += rem;
                    rem = 0;
                }
            }
        }
        if(rem > 0) return {};
        return ans;
    }
};