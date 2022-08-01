class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> graph;
        unordered_set<string> supp, rec;
        map<string,int> indegree;
        for(auto it: supplies) supp.insert(it);
        for(auto it: recipes) rec.insert(it);
        
        for(int i = 0; i < recipes.size(); i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                if(supp.find(ingredients[i][j]) != supp.end() || rec.find(ingredients[i][j]) != rec.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    if(indegree.find(ingredients[i][j]) == indegree.end())
                        indegree[ingredients[i][j]] = 0;
                }
                indegree[recipes[i]]++;
            }
        }
        
        
        queue<string> q;
        vector<string> ans;
        
        for(auto itr: indegree){
            if(itr.second == 0){
                q.push(itr.first);
            }
        }
        
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            
            for(auto it: graph[temp]){
                if(--indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};