class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        
        int cnt = 0, n = nums.size(), idx1 = -1, idx2 = -1;

        
        for(int i = 0; i < n; i++){
            if(temp[i] != nums[i]){
                idx1 = i;
                break;
            }
        }
        
        for(int i = n - 1; i >= 0; i--){
           if(temp[i] != nums[i]){
                idx2 = i;
                break;
            } 
        }
        
        if(idx1 == -1 && idx2 == -1)
            return 0;
        
        return (idx2 - idx1 + 1);
    }
};