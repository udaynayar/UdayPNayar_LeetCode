class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int m, int n, int k) {
        
        if (k == word.length()) return true;
        
        if (i<0 || j<0 || i>=m || j>=n)
            return false;
        
        
        
        
        
        if (word[k]!= board[i][j]) return false;
        char temp = board[i][j];
        board[i][j]=' ';
        
        bool res = dfs(board, word, i+1, j, m, n, k+1) || dfs(board, word, i-1,j, m, n, k+1) || dfs(board, word, i, j-1, m, n, k+1) || dfs(board, word, i, j+1, m, n, k+1);
        
        board[i][j] = temp;
        return res;
    } 
        
        
        
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i=0;i<m;i++) {
            
            for (int j=0;j<n;j++) {
                if (board[i][j]==word[0] && dfs(board, word, i, j, m, n, 0))return true;
                
            }
            
            
        }
        return false;
    }
};