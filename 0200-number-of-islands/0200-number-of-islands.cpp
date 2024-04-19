class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<bool>>& visited) {
        
        if (i<0 || j<0 || i>=m || j>=n || visited[i][j] || grid[i][j]=='0') return;
        visited[i][j]=true;
        
        dfs(grid,i+1,j,m,n, visited);
        dfs(grid,i-1,j,m,n, visited);
        dfs(grid,i,j+1,m,n, visited);
        dfs(grid,i,j-1,m,n, visited);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        
        for (int i=0; i<m; i++) {
            
            for (int j=0;j<n; j++) {
                if (grid[i][j]=='1' && !visited[i][j]) {
                    cout<<"kk"<<endl;
                    dfs(grid,i,j,m,n, visited);
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};