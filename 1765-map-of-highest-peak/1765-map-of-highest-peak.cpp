class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rsize = isWater.size();
        int csize = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rsize, vector<bool>(csize, false));
        for (int r = 0; r < rsize; r++) {
            for (int c = 0; c < csize; c++) {
                if (isWater[r][c] == 1) {
                    visited[r][c] = true;
                    q.push({r, c});
                    isWater[r][c] = 0;  
                }
            }
        }
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr < 0 || nc < 0 || nr >= rsize || nc >= csize || visited[nr][nc])
                        continue;  

                    visited[nr][nc] = true;
                    isWater[nr][nc] = step;   
                    q.push({nr, nc});
                }
            }
            step++;
        }

        return isWater;
    }
};