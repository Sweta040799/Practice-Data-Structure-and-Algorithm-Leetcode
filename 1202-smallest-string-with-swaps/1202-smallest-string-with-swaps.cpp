class Solution {
public:
    int findpar(vector<int>& par, int u){
        if(u == par[u])
            return u;
        return par[u] = findpar(par, par[u]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> par(n,0), rnk(n,0);
        
        for(int i = 0; i < n; i++)
            par[i] = i;
        
        for(auto& it : pairs){
            int u = findpar(par,it[0]);
            int v = findpar(par,it[1]);
            
            if(rnk[u] > rnk[v])
                par[v] = u;
                
            else if(rnk[u] < rnk[v])
                par[u] = v;
                    
            else{
                par[v] = u;
                rnk[u]++;
            }  
        }
        
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++){
            int root = findpar(par, i);
            adj[root].push_back(i);
        }
        
        string ans(n, ' ');
        for(int i = 0; i < n; i++){
            vector<char> ch;
            for(auto& it : adj[i])
                ch.push_back(s[it]);
        
            sort(ch.begin(),ch.end());

            for(int j = 0; j < ch.size(); j++)
                ans[adj[i][j]] = ch[j];
        }
        return ans;
    }
};