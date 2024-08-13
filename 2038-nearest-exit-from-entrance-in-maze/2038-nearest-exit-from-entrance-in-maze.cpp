class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0;
        int n = maze.size();
        int m = maze[0].size();
        int sr = entrance[0];
        int sc = entrance[1];
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        q.push({sr, sc});

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [row, col] = q.front();
                q.pop();
                
                if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                    (row != sr || col != sc)) {
                    return ans;
                }

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        maze[nrow][ncol] == '.' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};