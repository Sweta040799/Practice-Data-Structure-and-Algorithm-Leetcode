class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        vector<int> visited(n,0);
        for(int i = 0; i < times.size() ; i++)
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        
        // dijkstra algorithm
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto itr: adj[node]){
                if((!visited[itr.first] || visited[itr.first] > time + itr.second) && itr.first != k-1){
                    visited[itr.first] = time + itr.second;
                    pq.push({visited[itr.first],itr.first});
                }
            }
        }
        for(int i = 0; i < n ; i++)
            if(visited[i] == 0 && i != k-1)
                return -1;
        return *max_element(visited.begin(),visited.end());
    }
};