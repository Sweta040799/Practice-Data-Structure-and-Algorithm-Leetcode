class Solution {
public:
    bool ans = true;
    bool dfs(vector<vector<int>>& graph,vector<int>& color, int s){
        for(auto node : graph[s]){
            if(color[node] == -1){
                color[node] = 1-color[s];
                dfs(graph,color,node);
            }
            else{
                if(color[node] == color[s])
                    ans = false;
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int vertex = graph.size();
       vector<int> color(vertex,-1);
        
        for(int i=0;i<vertex;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(graph,color,i))
                    return false;
            }
        }
      return true;  
    }
};