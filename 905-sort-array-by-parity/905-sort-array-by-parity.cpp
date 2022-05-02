class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<pair<int,int>> vp;
        
        for(int i = 0; i < nums.size(); i++)
            vp.push_back({nums[i] % 2, nums[i]});
        
        sort(vp.begin(),vp.end());
        
        for(int i = 0; i < vp.size(); i++)
            nums[i] = vp[i].second;
        
        return nums;
        
    }
};