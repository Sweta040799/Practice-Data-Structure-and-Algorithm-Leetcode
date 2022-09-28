class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int j = 0, res = 0, freq = 0;
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            freq = max(freq, mp[s[i]]);
            
            while((i - j + 1) - freq > k){
                mp[s[j]]--;
                j++;
            }
            
            res = max(res, i - j + 1);
            
        }
        
        return res;
    }
};