class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& grid, int r, int c, int rsize, int csize) {
        if (r < 0 || c < 0 || r >= rsize || c >= csize || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            dfs(grid,nx, ny, rsize, csize);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int island = 0;
        int rsize = grid.size();
        int csize = grid[0].size();

        for (int r = 0; r < rsize;r++) {
            for (int c = 0; c < csize; c++) {
                if (grid[r][c] == '1') {
                    island++;
                    dfs(grid, r, c, rsize, csize);
                }
            }
        }
        return island;
    }
};