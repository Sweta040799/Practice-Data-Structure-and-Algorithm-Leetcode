class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size(), ans = 0;
       unordered_set<int> temp(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(temp.find(nums[i]) == temp.end()) continue;
            temp.erase(nums[i]);
            
            int prev = nums[i] - 1, next = nums[i] + 1;
            
            while(temp.find(prev) != temp.end()){
                temp.erase(prev);
                prev--;
            }
            while(temp.find(next) != temp.end()){
                temp.erase(next);
                next++;
            }
            
            ans = max(ans, next - prev - 1);
        }
        
        return ans;
    }
};