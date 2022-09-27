class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        queue<int> q;
        int type = 0, res = 0, n = fruits.size();
        
        for(int i = 0; i < n; i++){
            mp[fruits[i]]++;
            q.push(i);
            while(mp.size() > 2){
                if(--mp[fruits[q.front()]] == 0){
                    mp.erase(fruits[q.front()]);    
                }
                q.pop();
            }
            res = max(res, i - q.front() + 1);
        }
        
        
        return res;
    }
};