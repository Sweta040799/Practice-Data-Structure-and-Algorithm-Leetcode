class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> greaterRight(nums.size(),0);
        vector<int> smallerLeft(nums.size(),0);
        stack<int> s;
        
        for(int i = nums.size()-1;i>=0;i--){
            if(s.size() == 0){
                greaterRight[i] = -169;
            }
            else if(s.size()>0 and s.top() > nums[i]){
                greaterRight[i] = s.top();
            }
            else if(s.size()>0 and s.top() <= nums[i]){
                while(s.size() > 0 and s.top() <= nums[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    greaterRight[i] = -169;
                }
                else{
                    greaterRight[i] = s.top();
                }
            }
            s.push(nums[i]);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i = 0;i<nums.size();i++){
            if(s.size() == 0){
                smallerLeft[i] = -169;
            }
            else if(s.size()>0 and s.top() < nums[i]){
                smallerLeft[i] = s.top();
            }
            else if(s.size()>0 and s.top() >= nums[i]){
                while(s.size() > 0 and s.top() >= nums[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    smallerLeft[i] = -169;
                }
                else{
                    smallerLeft[i] = s.top();
                }
            }
            s.push(nums[i]);
        }
       
        for(int i = 0; i < nums.size();i++){
            if(greaterRight[i]!=-169 and smallerLeft[i]!=-169){
                return true;
            }
        }
        
        return false;
    }
};