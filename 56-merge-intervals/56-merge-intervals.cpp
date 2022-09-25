class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            
            return a[0] < b[0];
            
        };
        sort(intervals.begin(), intervals.end(),comp);
        
        int a = intervals[0][0], b = intervals[0][1];
        vector<vector<int>> ans;
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > b){
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
            else if(intervals[i][1] > b){
                b = intervals[i][1];
            }
        }
        ans.push_back({a,b});
        return ans;
    }
};