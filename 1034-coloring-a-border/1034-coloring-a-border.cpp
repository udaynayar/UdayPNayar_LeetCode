class Solution {
public:
    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int row, int col, int m, int n, stack<pair<int,int>>& st) {
        
        visited[row][col]=true;
        bool f = false;
        
        if (row == 0) {
            st.push(pair<int,int>{row, col});
            f = true;
        }
        else if (!visited[row-1][col]) {
            
            if (grid[row-1][col]==grid[row][col]) dfs(visited, grid, row-1, col, m, n, st);
            
            else if (!f) {
                st.push(pair<int,int>{row, col});
                f=true;
            }
            
            
        }   
        
        if (col == 0) {
            if (!f) st.push(pair<int,int>{row, col});
            f = true;
        }
        else if (!visited[row][col-1]) {
            
            if (grid[row][col-1]==grid[row][col]) dfs(visited, grid, row, col-1, m, n, st);
            
            else if (!f) {
                st.push(pair<int,int>{row, col});
                f=true;
            }
            
            
        }
        
        if (row == m-1) {
            if (!f) st.push(pair<int,int>{row, col});
            f=true;
        }
        else if (!visited[row+1][col]) {
            
            if (grid[row+1][col]==grid[row][col]) dfs(visited, grid, row+1, col, m, n, st);
            
            else if (!f) {
                st.push(pair<int,int>{row, col});
                f=true;
            }
            
            
        }
        
        if (col == n-1) {
            if (!f) st.push(pair<int,int>{row, col});
            f=true;
        }
        else if (!visited[row][col+1]) {
            
            if (grid[row][col+1]==grid[row][col]) dfs(visited, grid, row, col+1, m, n, st);
            
            else if (!f) {
                st.push(pair<int,int>{row, col});
                f=true;
            }
            
            
        }
        
    }
    
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int,int>> st;
        dfs(visited, grid, row, col, m, n, st);
        
        while (!st.empty()) {
            int i = st.top().first;
            int j = st.top().second;
            st.pop();
            grid[i][j]=color;
        }
        return grid;        
    }
};