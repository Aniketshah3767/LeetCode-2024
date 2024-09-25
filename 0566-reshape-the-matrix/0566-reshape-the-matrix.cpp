class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r, vector<int> (c, 0));
        int n = mat.size();
        int m = mat[0].size();
        if (r * c != m * n) return mat;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[k / c][k % c] = mat[i][j];
                k++;
            }
        }
        return res;
    }
};