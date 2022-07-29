class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int cnt = target[0], n = target.size(), prev = target[0];
        
        for(int i = 1; i < n; i++){
            if(target[i] > target[i - 1]){
                cnt += target[i] - target[i - 1];
                prev = target[i];
            }
        }
        
        return cnt;
    }
};