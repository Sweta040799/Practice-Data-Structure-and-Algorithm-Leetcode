class Solution {
public:
    int dp[71][71][71];
    //3d dp of row,rob1,rob2
    
//     int recur(int i, int j1, int j2, vector<vector<int>> grid, int r, int c){
//         if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
//             return INT_MIN;
//         if(i == r - 1){
//             if(j1 == j2)
//                 return grid[i][j1];
//             else
//                 return grid[i][j1] + grid[i][j2];
//         }
        
//         if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
//         int mx = INT_MIN;
        
//         for(int m = -1; m < 2; m++){
//             for(int n = -1; n < 2; n++){
//                 int val = 0;
//                 val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
//                 val += recur(i + 1, j1 + m, j2 + n, grid, r, c);
//                 mx = max(mx, val);
//             }
//         }
        
//         return dp[i][j1][j2] = mx;
//     }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int r = grid.size(), c = grid[0].size();
        
        //base case
        for(int i = 0; i < c; i++){
            for(int j  = 0; j < c; j++){
                if(i == j)
                    dp[r - 1][i][j] = grid[r - 1][i];
                else
                    dp[r-1][i][j] = grid[r - 1][i] + grid[r - 1][j];
            }
        }
        
        //recurrence
        for(int i = r - 2; i>= 0; i--){
            
            for(int j1 = 0; j1 < c; j1++){
                
                for(int j2 = 0; j2 < c; j2++){
                 
                    int mx = INT_MIN;
                    
                    for(int dj1 = -1; dj1 < 2; dj1++){
                        
                        for(int dj2 = -1; dj2 < 2; dj2++){
                            
                            int val = 0;
                            val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            
                            if(j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c){
                                
                                val += dp[i + 1][j1 + dj1][j2 + dj2];
                                
                            }
                            else
                                val += -1e8;
                                
                            mx = max(mx,val);
                            
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        
        return dp[0][0][c - 1];
    }
};