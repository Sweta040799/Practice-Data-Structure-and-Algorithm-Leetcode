class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0)
                    vp.push_back({i, j});
            }
        }
        
        for(int l = 0; l < vp.size(); l++){
            int r = vp[l][0], c = vp[l][1];
            
            for(int i = 0; i < n; i++)
                matrix[i][c] = 0;
            
            for(int j = 0; j < m; j++)
                matrix[r][j] = 0;
        }
    }
};