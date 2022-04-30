class Solution {
public:
    unordered_map<string,unordered_map<string,double>> adj;
    
    void recur(unordered_map<string,int>& visit, string src, string dest, double& res, double temp){
        if(visit[src]){
            return;
        }
        if(src == dest){
            res = temp;
            return;
        }
        visit[src] = 1;
        for(auto& it : adj[src]){
            recur(visit,it.first,dest,res,temp * it.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size() ; i++){
            adj[equations[i][0]].insert({equations[i][1],values[i]});
            adj[equations[i][1]].insert({equations[i][0],1.0/values[i]});
        }
        vector<double> ans;
        for(auto& it : queries){
            string src = it[0];
            string dest = it[1];
            unordered_map<string,int> visit;
             if(adj.find(src) == adj.end())
                 ans.push_back(-1.00000);
            else{
                double res = 1.00, temp = -1.00;
                recur(visit,src,dest,res,temp);
                ans.push_back(-res);
            }
        }
        return ans;
    }
};