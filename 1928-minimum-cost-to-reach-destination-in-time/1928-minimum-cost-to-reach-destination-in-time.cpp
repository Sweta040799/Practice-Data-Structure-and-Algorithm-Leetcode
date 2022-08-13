class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> graph[n];
        
        for(auto i: edges){
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> visit(n, 0), max_cost(n, INT_MAX), max_time(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({passingFees[0], 0, 0});
        max_cost[0] = passingFees[0];
        max_time[0] = 0;
        
        while(!pq.empty()){
            auto temp = pq.top();
            int currCost = temp[0];
            int currTime = temp[1];
            int currNode = temp[2];
            pq.pop();
            
            
            for(auto i: graph[currNode]){
                if(i[1] + currTime <= maxTime){
                    if(passingFees[i[0]] + currCost < max_cost[i[0]]){
                        max_cost[i[0]] = passingFees[i[0]] + currCost;
                        max_time[i[0]] = i[1] + currTime;
                        pq.push({max_cost[i[0]], max_time[i[0]], i[0]});
                    }
                    else if(i[1] + currTime < max_time[i[0]]){
                        max_time[i[0]] = i[1] + currTime;
                        pq.push({passingFees[i[0]] + currCost, max_time[i[0]], i[0]});
                    }
                }
                
                
            }
        }
        
        return (max_cost[n - 1] == INT_MAX) ? -1 : max_cost[n - 1];
    }
};