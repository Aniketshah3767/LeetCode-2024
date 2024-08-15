class Solution {

private:
    bool istrue(vector<vector<int>>& grid, int row, int col) {
        vector<bool> seen(10, false);
        for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }
    //sum of first row
    int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
    //check row;
    for(int i = row ; i < row+3; i++){
        if(grid[i][col] + grid[i][col+1] + grid[i][col+2] != sum)
            return false;
    }

    //check col;
    for(int j = col ; j < col+1 ; j++){
        if(grid[row][j] + grid[row+1][j] + grid[row+2][j] != sum)
            return false;
    }

    //check diag
    if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum)
        return false;

    if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum)
        return false;
    
    return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i <= n-3 ; i++){
            for(int j = 0 ; j <= m-3 ; j++){
                if(istrue(grid,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};