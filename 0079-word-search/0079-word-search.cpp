class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int rows, cols;

    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int i,
                    vector<vector<bool>>& visited) {
        // bounds check
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
    
        if (visited[r][c]) return false;
        // character mismatch
        if (board[r][c] != word[i]) return false;
        // matched the last character -> whole word found
        if (i == word.size() - 1) return true;

        
        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (backtrack(board, word, nr, nc, i + 1, visited))
                return true;
        }

  
        visited[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, word, r, c, 0, visited))
                    return true; 
            }
        }
        return false;
    }
};