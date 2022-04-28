class Solution {
public:   
    int longestStrChain(vector<string>& words) {
        int n = words.size(),mx = 1;
        unordered_map<string, int> dp;
        auto comp = [](string &a, string &b){
            return (a.size() < b.size());
        };
        sort(words.begin(),words.end(),comp);
        for(auto& it : words){
            for(int j = 0; j < it.size(); j++){
                string temp = it.substr(0,j) + it.substr(j + 1);
                dp[it] = max(dp[it], dp.find(temp) == dp.end() ? 1 : dp[temp] + 1);
            }
            
            mx = max(mx,dp[it]);
        }
        
        return mx;
    }
};