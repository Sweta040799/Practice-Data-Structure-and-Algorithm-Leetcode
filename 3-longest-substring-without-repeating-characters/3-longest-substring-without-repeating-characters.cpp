class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1);
        int res = 0, start = -1;
        for(int i = 0; i < s.size(); i++){
            if(freq[s[i]] > start){
                start = freq[s[i]];
            }
            freq[s[i]] = i;
            res = max(res, i - start);
        }
        
        return res;
    }
};