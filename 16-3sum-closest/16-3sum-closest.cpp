class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), low = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, h = n - 1;
            
            while(l < h){
                
                int curr = nums[i] + nums[l] + nums[h];
            
                
                if(abs(target - curr) <= abs(target - low))
                    low = curr;
                
                if(curr > target)
                    h--;
                
                else
                    l++;
            }
        
        }
       return low;        
    }
};