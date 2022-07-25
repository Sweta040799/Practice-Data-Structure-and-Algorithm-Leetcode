class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2*n);
        for(int i = n; i < 2*n; i++){
            nums[i] = nums[i - n];
        }
        stack<int> st;
        vector<int> ans(n,-1);
        
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i % n] = nums[st.top()];
            }
            
            st.push(i);
        }
        
        return ans;
    }
};