class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto comp = [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };
        
        sort(meetings.begin(), meetings.end(), comp);
        vector<int> ans, visit(n,0);
        vector<vector<int>> graph[n];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        // <pair<int,int>> q;
        q.push({0, 0});
        q.push({0, firstPerson});
        graph[0].push_back({firstPerson, 0});
        
        for(auto i: meetings){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        
        while(!q.empty()){
            int currTime = q.top().first;
            int currNode = q.top().second;
            q.pop();
            if(visit[currNode]) continue;
            visit[currNode] = 1;
            ans.push_back(currNode);
            
            for(auto it: graph[currNode]){
                if(!visit[it[0]] && it[1] >= currTime)
                    q.push({it[1],it[0]});
            }
        }
        
        
        
        return ans;
    }
};