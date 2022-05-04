class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        // for(auto& it : mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            int req = k - nums[i];
            if(mp[req] > 0){
                int ded = (nums[i] != req) ? min(mp[nums[i]],mp[req]) : mp[req]/2;
                cnt += ded;
                mp[nums[i]] -= ded;
                mp[req] -= ded;
            }
        }
        
        return cnt;
    }
};