class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> res(m,vector<int>(n,0));
        // res[m-1][n-1] = grid[m-1][n-1];
        for(int i = m - 1 ; i >= 0 ; i--) {
            for(int j = n - 1 ; j >= 0 ; j--) {
                int temp = INT_MAX;
                if(j + 1 < n) temp = min(temp,grid[i][j+1]);
                if(i + 1 < m) temp = min(temp,grid[i+1][j]);
                grid[i][j] += temp == INT_MAX ? 0 : temp;
                // cout<<i<<" "<<j<<" "<<grid[i][j]<<'\n';
            }
        }
        return grid[0][0];
    }
};