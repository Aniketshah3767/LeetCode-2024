class Solution {

private:
    bool istrue(vector<vector<int>>& grid, int row, int col) {
        set<int> s;

        // Check for duplicates and range within 3x3 subgrid
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9) {
                    return false;
                }
                s.insert(num);
            }
        }

        // Ensure that all numbers 1 through 9 are present exactly once
        if (s.size() != 9) {
            return false;
        }

        // Sum of the first row
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check each row
        for (int i = row; i < row + 3; i++) {
            if (grid[i][col] + grid[i][col + 1] + grid[i][col + 2] != sum) {
                return false;
            }
        }

        // Check each column
        for (int j = col; j < col + 3; j++) {
            if (grid[row][j] + grid[row + 1][j] + grid[row + 2][j] != sum) {
                return false;
            }
        }

        // Check diagonals
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) {
            return false;
        }
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) {
            return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (istrue(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
