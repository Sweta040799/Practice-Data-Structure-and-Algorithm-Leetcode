class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        
        for(auto i: nums){
            auto lb = lower_bound(res.begin(), res.end(), i);
            if(lb == res.end()) res.push_back(i);
            else *lb = i;
        }
        
        return res.size();
    }
};