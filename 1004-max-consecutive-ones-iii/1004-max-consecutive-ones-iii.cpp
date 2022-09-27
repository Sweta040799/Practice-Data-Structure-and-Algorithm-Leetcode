class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int res = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                if(k > 0){
                    k--;
                    cnt++;
                    q.push(i);
                }
                else if(!q.empty()){
                    res = max(res,cnt);
                    cnt = i - q.front() - 1;
                    q.pop();
                    k++;
                    i--;
                }
                else{
                   res = max(res,cnt);
                   cnt = 0;
                }
            }
        }
        
        res = max(res,cnt);
        return res;
    }
};