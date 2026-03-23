class orangesRotting {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int depth = 0;
        int max_depth = 0;
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, depth});
                }
            }
        }
        vector<pair<int,int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        while (!q.empty()) {
            vector<int> b =  q.front();
            q.pop();
            int i = b[0], j = b[1];
            max_depth = max(max_depth, b[2]);
            for (auto [dx, dy]:dir) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m &&
                    y >= 0 && y < n &&
                    (grid[x][y] == 1)) {
                    q.push({x, y, b[2] + 1});
                    grid[x][y] = 2;
                }
            }
        }
        for (auto& row : grid) {
            if (find(row.begin(), row.end(), 1) != row.end()) {
                return -1;
            } 
        }
        return max_depth;
    }
};