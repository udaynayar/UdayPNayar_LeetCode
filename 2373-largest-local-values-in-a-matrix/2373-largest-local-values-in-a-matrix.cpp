class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        
        for (int i=1; i<n-1; i++) {
            for (int j=1;j<n-1;j++) {
                
                int x = grid[i][j];
                for (int a=-1;a<2;a++)
                    for (int b=-1;b<2;b++)
                        if (x < grid[i+a][j+b]) 
                            x = grid[i+a][j+b];
                
                ans[i-1][j-1] = x;
                
            }
        }
        
        
        
        return ans;
    }
};