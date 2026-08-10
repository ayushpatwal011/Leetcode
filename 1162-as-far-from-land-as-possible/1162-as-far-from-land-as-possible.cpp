class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    int maxDistance(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int csize = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rsize, vector<bool>(csize, false));

        for (int r = 0; r < rsize; r++) {
            for (int c = 0; c < csize; c++) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        if (q.empty() || q.size() == rsize * csize) return -1;

        int step = -1; 

        // STEP 2:
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr < 0 || nc < 0 || nr >= rsize || nc >= csize || visited[nr][nc]) {
                        continue;  
                    }

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            step++; 
        }

        return step;
    }
};