​<h2>Standard Dynamic Programming Question</h2>

<h3>Recursive Code:</h3>

```
class Solution {
public:
    int Recur(vector<int>& nums, int prev, int curr){
        if(curr == nums.size()){
            return 0;
        }
        
        int left = 0;
        if(prev == -1 || nums[prev] < nums[curr])
            left = 1 + Recur(nums, curr, curr + 1);
        
        int right = Recur(nums, prev, curr + 1);
        
        return max(left,right);
    }
    int lengthOfLIS(vector<int>& nums) {
        return Recur(nums, -1, 0);
    }
};
```
  
  
  
 <h3>Memoized Code:</h3>

```  
class Solution {
public:
    int dp[2501][2501];
    int Recur(vector<int>& nums, int prev, int curr){
        if(curr == nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[prev][curr] != 0)
            return dp[prev][curr];
        
        int left = 0;
        if(prev == -1 || nums[prev] < nums[curr])
            left = 1 + Recur(nums, curr, curr + 1);
        
        int right = Recur(nums, prev, curr + 1);
        
        if(prev != -1)        
            return dp[prev][curr] = max(left,right);
        return max(left,right);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        return Recur(nums, -1, 0);
    }
};
```
  
<h3>Memoized Code + Space Optimized</h3>

```
class Solution {
public:
    int dp[2501];
    int Recur(vector<int>& nums, int prev, int curr){
        if(curr == nums.size()){
            return 0;
        }
        
        if(prev != -1 && dp[prev] != 0)
            return dp[prev];
        
        int left = 0;
        if(prev == -1 || nums[prev] < nums[curr])
            left = 1 + Recur(nums, curr, curr + 1);
        
        int right = Recur(nums, prev, curr + 1);
        
        if(prev != -1)        
            return dp[prev] = max(left,right);
        return max(left,right);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        return Recur(nums, -1, 0);
    }
};
```
