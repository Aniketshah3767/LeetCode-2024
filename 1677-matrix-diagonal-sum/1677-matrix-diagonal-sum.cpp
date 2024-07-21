class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    sum += mat[i][j]; // diagnol sida wala
                } else if (i == j && n - j - 1 == i) {
                    sum += mat[i][j]; // to skip the middle one in odd wala mah
                } else if (i == n - j - 1) { // add the other side of the
                                             // diagnol
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};