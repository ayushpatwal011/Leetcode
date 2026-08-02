class Solution {
public:
    vector<vector<string>> ans;

    bool checkCol(int col, int n, vector<vector<bool>>& stored) {
        for (int i = 0; i < n; i++)
            if (stored[i][col]) return false;
        return true;
    }

    bool checkDiagonal(int row, int col, int n, vector<vector<bool>>& stored) {
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
            if (stored[r][c]) return false;
        for (int r = row, c = col; r >= 0 && c < n; r--, c++)
            if (stored[r][c]) return false;
        return true;
    }

    void backtrack(int row, int n, vector<vector<bool>>& stored) {
        if (row == n) {
            vector<string> board;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (bool x : stored[i]) s += x ? 'Q' : '.';
                board.push_back(s);
            }
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (checkCol(col, n, stored) && checkDiagonal(row, col, n, stored)) {
                stored[row][col] = true;
                backtrack(row + 1, n, stored);
                stored[row][col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> stored(n, vector<bool>(n, false));
        backtrack(0, n, stored);
        return ans;
    }
};