#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;

        // Process boundary cells only
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '#';
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = '#';
            }
        }

        // Perform BFS from boundary-connected 'O' cells
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 'O') {
                    board[newRow][newCol] = '#';
                    q.push({newRow, newCol});
                }
            }
        }

        // Flip 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
