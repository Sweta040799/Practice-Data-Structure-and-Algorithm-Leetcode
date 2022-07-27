class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indeg(n,0),dist(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        queue<int> q;
        
        for(int i = 0; i < relations.size(); i++){
            graph[relations[i][0] - 1].push_back(relations[i][1] - 1);
            indeg[relations[i][1] - 1]++;
        }
        
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
                dist[i] = time[i];
            }
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(auto it : graph[temp]){
                dist[it] = max(dist[it], dist[temp] + time[it]);
                if(--indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return *max_element(dist.begin(), dist.end());
    }
};