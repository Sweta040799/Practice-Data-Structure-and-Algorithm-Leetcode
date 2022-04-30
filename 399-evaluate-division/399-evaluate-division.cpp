class Solution {
public:
    unordered_map<string,unordered_map<string,double>> graph;
    void dfs(string src,string des, double &cnt, double temp, unordered_map<string,int>& visit){
        if(visit.count(src)){
            return;
        }
        
        if(src == des){
            cnt = temp;
            return;
        }
        visit[src] = 1;
        for(auto node : graph[src]){
           dfs(node.first,des,cnt,temp*node.second,visit); 
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].insert({equations[i][1],values[i]});
            graph[equations[i][1]].insert({equations[i][0],1.0/values[i]});
        }
        
        int n = queries.size();
        
        vector<double> ans;
        for(auto it: queries){
            string source = it[0];
            string destination = it[1];
            unordered_map<string,int> visit;
            
            double count = 1.0;
            double temp = -1.0;
            
            if(graph.find(source) == graph.end())
                 ans.push_back(-1.00000);
            
            else{
            dfs(source,destination,count,temp,visit);
            ans.push_back(-count);
            }
        }
        return ans;
    }
};