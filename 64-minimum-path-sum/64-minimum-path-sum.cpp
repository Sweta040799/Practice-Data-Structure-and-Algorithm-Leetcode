class Solution {
public:
    int dp[201][201];
    int Recur(vector<vector<int>>& grid, int r, int c){
        if(r == 0 && c == 0) return grid[r][c];
        if(r < 0 || c < 0) return 100000000;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int left = grid[r][c] + Recur(grid, r, c - 1);
        int top = grid[r][c] + Recur(grid, r - 1, c);
        
        return dp[r][c] = min(left, top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return Recur(grid, grid.size() - 1, grid[0].size() - 1);
    }
};