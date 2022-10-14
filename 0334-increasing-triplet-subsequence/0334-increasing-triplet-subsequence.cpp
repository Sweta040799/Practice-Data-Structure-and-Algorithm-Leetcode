class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> ng(n), ps(n);
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            
            ps[i] = (st.empty()) ? -169 : nums[st.top()];
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()])
                st.pop();
            
            ng[i] = (st.empty()) ? -169 : nums[st.top()];
            st.push(i);
        }
        
        for(int i = 0; i < n; i++){
            if(ps[i] != -169 && ng[i] != -169)
                return true;
        }
        
        return false;
    }
};